# Feedback: Training 1 - Sensor Alert Analyzer

Reviewed file:

- `examtraining/training1/examtraining1.cpp`

Compile check used:

```bash
g++ -std=c++20 -Wall -Wextra -pedantic examtraining\training1\examtraining1.cpp -o examtraining\training1\examtraining1_check.exe
```

Result: did not compile.

## Score

Estimated score: **13 / 30**

- Bug hunt / explanations: 4 / 7
- Corrected class design and conventions: 4 / 7
- Safe average behavior: 3 / 5
- Template function: 0 / 5
- `main()` tests: 1 / 3
- Theory understanding: 1 / 3

The biggest deduction is compilation. In the exam, non-compiling code loses many
points even when the idea is partly right.

## What Was Good

- You correctly made `readings` private.
- You recognized that `==` is needed instead of assignment in the condition.
- You initialized `sum` to `0`.
- You used `const SensorReading&` in loops, which avoids copying and prevents
  accidental changes.
- You added a missing-sensor guard with `count == 0`.
- Your `main()` creates realistic test data and checks existing sensors.

## Critical Issues

### 1. Template declaration is incomplete

Your code starts with:

```cpp
template <typename T>
T find_largest_value(const std::vector<T>& values)
//not sure how to add this properly or how this is added properly
```

This declares a function header but never provides a body or semicolon. Because of
that, the compiler thinks the following `struct SensorReading` is part of an
invalid function definition.

Fix:

```cpp
template <typename T>
T find_largest_value(const std::vector<T>& values)
{
    if (values.empty())
    {
        throw std::invalid_argument("values must not be empty");
    }

    return *std::max_element(values.begin(), values.end());
}
```

Also add:

```cpp
#include <stdexcept>
```

### 2. Parameter should be `const std::string&`

You wrote:

```cpp
double calculateAverage(const std::string sensor_name) const
```

This makes the local copy const, but it still copies the string. Better:

```cpp
double calculateAverage(const std::string& sensor_name) const
```

### 3. `counts` should not be a member variable

You made `counts` a private attribute:

```cpp
std::map<std::string, int> counts;
```

This is risky because every call to `printSensorNames()` adds counts again. If you
call it twice, all values double.

Better: keep `counts` local inside `printSensorNames()`.

### 4. `this->` is not required here

Your comment says `this->` was missing and could cause errors. In this task, it is
not required unless a parameter has the same name as a member variable.

This is fine:

```cpp
readings.push_back(reading);
```

Use `this->` only when it improves clarity or resolves shadowing.

### 5. Missing test for missing sensor

The task required a missing sensor case. Your `main()` only tests existing
sensors: Temperature, Humidity, Pressure.

Add:

```cpp
std::cout << alertSystem.calculateAverage("Voltage") << '\n';
```

### 6. Missing `find_largest_value` test

The task required testing the template function in `main()`. This is currently
missing.

Example:

```cpp
std::vector<double> values{22.5, 23.0, 21.8};
std::cout << find_largest_value(values) << '\n';
```

### 7. `addReading` can avoid a copy

Your version:

```cpp
void addReading(SensorReading reading)
```

Better:

```cpp
void addReading(const SensorReading& reading)
```

For this small struct it is not catastrophic, but the convention is good practice.

## Correct Theory Answers As Comments

You can paste these comments into your solution or use them as reference answers.

```cpp
// 1. Why should readings be private?
// readings should be private because it is internal state of AlertSystem.
// If outside code can modify it directly, the class cannot protect its own
// invariants. A public addReading method gives controlled access.

// 2. Why is const std::string& better than std::string for read-only parameters?
// std::string passed by value creates a copy. const std::string& avoids that copy
// and also documents that the function will not modify the argument.

// 3. What does structured binding do?
// In for (const auto& [name, count] : counts), structured binding splits each
// map element into its key and value. name refers to the key, count to the value.
// const auto& avoids copying each map entry.

// 4. What could go wrong with sum / count?
// If count is 0, the code divides by zero. That can happen when there are no
// readings or no readings matching the requested sensor name. The function must
// handle this case before division.

// 5. Is this task static or dynamic polymorphism?
// The template function is static polymorphism because the compiler creates the
// needed function version at compile time. There is no dynamic polymorphism here
// because there are no virtual functions, base-class pointers, or overrides.
```

## Reference Shape For A Correct Solution

```cpp
#include <algorithm>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

struct SensorReading
{
    std::string sensor_name;
    double value;
    std::string unit;
};

template <typename T>
T find_largest_value(const std::vector<T>& values)
{
    if (values.empty())
    {
        throw std::invalid_argument("values must not be empty");
    }

    return *std::max_element(values.begin(), values.end());
}

class AlertSystem
{
private:
    std::vector<SensorReading> readings;

public:
    void addReading(const SensorReading& reading)
    {
        readings.push_back(reading);
    }

    double calculateAverage(const std::string& sensor_name) const
    {
        double sum = 0.0;
        int count = 0;

        for (const SensorReading& reading : readings)
        {
            if (reading.sensor_name == sensor_name)
            {
                sum += reading.value;
                count++;
            }
        }

        if (count == 0)
        {
            throw std::invalid_argument("No readings found for sensor");
        }

        return sum / count;
    }

    void printSensorNames() const
    {
        std::map<std::string, int> counts;

        for (const SensorReading& reading : readings)
        {
            counts[reading.sensor_name]++;
        }

        for (const auto& [name, count] : counts)
        {
            std::cout << name << ": " << count << '\n';
        }
    }
};
```

## Next Drill

Do a 10-minute correction pass:

1. Make your current file compile.
2. Implement `find_largest_value`.
3. Move `counts` back into `printSensorNames()`.
4. Add one missing-sensor test and one template test.

Do not add new features. Focus only on correctness and course conventions.
