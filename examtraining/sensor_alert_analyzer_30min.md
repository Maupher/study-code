# 30-Minute Training Task: Sensor Alert Analyzer

## Goal

Practice OOP, encapsulation, `const` correctness, STL containers,
`std::map`, structured bindings, templates, and bug analysis.

## Timebox

- 5 min: read the starter code and identify issues
- 15 min: fix and implement
- 5 min: test in `main()`
- 5 min: answer theory questions

## Starter Code

```cpp
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

struct SensorReading
{
    std::string sensor_name;
    double value;
    std::string unit;
};

class AlertSystem
{
public:
    std::vector<SensorReading> readings;

    void addReading(SensorReading reading)
    {
        readings.push_back(reading);
    }

    double calculateAverage(std::string sensor_name)
    {
        double sum;
        int count = 0;

        for (SensorReading reading : readings)
        {
            if (reading.sensor_name = sensor_name)
            {
                sum += reading.value;
                count++;
            }
        }

        return sum / count;
    }

    void printSensorNames()
    {
        std::map<std::string, int> counts;

        for (SensorReading reading : readings)
        {
            counts[reading.sensor_name]++;
        }

        for (auto pair : counts)
        {
            std::cout << pair.first << ": " << pair.second << "\n";
        }
    }
};
```

## Tasks

### Part 1: Bug Hunt

Find at least 7 problems in the starter code.

For each issue, write down:

- what the problem is
- why it is problematic
- how you fixed it

### Part 2: Rewrite The Class

Rewrite the code according to the course conventions.

Required improvements:

- make member variables private
- use `const std::string&` where appropriate
- mark methods as `const` where appropriate
- initialize all variables
- avoid assignment inside conditions
- handle the empty/no matching sensor case safely
- avoid unnecessary copies in loops
- keep the class interface clear and small

### Part 3: Add A Template Function

Add this template function:

```cpp
template <typename T>
T find_largest_value(const std::vector<T>& values);
```

The function must handle an empty vector safely.

Choose one strategy:

- throw an exception for an empty vector
- return a fallback value
- use another clearly explained approach

Write a short comment explaining your decision.

### Part 4: Test In `main()`

Your `main()` must:

- create an `AlertSystem`
- add at least 5 readings
- print sensor counts
- calculate the average for one existing sensor
- test one missing sensor case
- test `find_largest_value`

Use this compile command:

```bash
g++ -std=c++20 -Wall -Wextra -pedantic sensor_alert_analyzer.cpp -o sensor_alert_analyzer
```
--> i used g++ .\examtraining1.cpp -o examtraintest


## Theory Questions

Answer briefly in comments or below your code:

1. Why should `readings` be private? -> answered in the comments
2. Why is `const std::string&` better than `std::string` for read-only parameters? -> also answewed in comments
3. What does structured binding do in this loop? -> What is this??

```cpp
for (const auto& [name, count] : counts)
{
    std::cout << name << ": " << count << '\n';
}
```

4. What could go wrong with `sum / count`? -> sum could be divided by zero what could result in unexpected and wild errors that cant be foreseen
5. Is this task static or dynamic polymorphism? Explain briefly. -> This task is static bc the functions dont react to diffrent sensor types and use diffrent functions depending on this. Polymoph would be an Interface class sensor as base and then child classes for specific sensors like humidity with the attribute pressure and specific calculations and one temperature also reacting below to EU use "grad Celsius" or the US version etc.

## Grading Checklist

Score out of 30:

- 7 points: at least 7 valid issues found and explained
- 7 points: corrected class design and course conventions
- 5 points: safe average calculation behavior
- 5 points: correct template function and empty-vector handling
- 3 points: useful `main()` tests
- 3 points: theory answers

Automatic deductions:

- public mutable `readings`
- uninitialized `sum`
- assignment in condition
- division by zero
- missing `const` on read-only methods
- no empty-vector handling in `find_largest_value`
