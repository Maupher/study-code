#pragma once

#include <vector>
#include <algorithm>
#include <string>

class FlightRecAnalysys{

    friend class FlightRecorder;
    private: 
        std::vector<int> flightRec;

    public:
        FlightRecAnalysys(std::vector<int> flightRec);
        void addFlightRec(int rec);
        void removeFlightRec(int rec);
        int findFlightRec(int rec);
        int getFlightRecCount();
        std::vector<int> getSortedFlightRec();

        void noiseCleaning();

        virtual void printFlightRec();
};
