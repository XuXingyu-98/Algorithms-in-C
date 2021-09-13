//
//  main.cpp
//  Calendar Matching
//
//  Created by Federico Xu on 24/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct StringMeeting{
    string start;
    string end;
};

struct Meeting{
    int start;
    int end;
};

int timeToMinutes(string time);
string minutesToTime(int minutes);
vector<Meeting> updateCalendar(vector<StringMeeting> calendar, StringMeeting dailyBounds);
vector<StringMeeting> calendarMatching(vector<StringMeeting> calendar1, StringMeeting dailyBounds1, vector<StringMeeting> calendar2, StringMeeting dailyBounds2, int meetingDuration);
vector<Meeting> merge(vector<Meeting> calendar1, vector<Meeting> calendar2);
vector<Meeting> flatten(vector<Meeting> calendar);
vector<StringMeeting> getMatching(vector<Meeting> calendar, int meetingDuration);
void display(vector<StringMeeting> array);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<StringMeeting> calendar1 = {{"9:00", "10:30"}, {"12:00", "13:00"}, {"16:00", "18:00"}};
    vector<StringMeeting> calendar2 = {{"10:00", "11:30"}, {"12:30", "14:30"}, {"14:30", "15:00"}, {"16:00", "17:00"}};
    StringMeeting dailyBounds1 = {"9:00", "20:00"};
    StringMeeting dailyBounds2 = {"10:00", "18:30"};
    int meetingDuration = 30;
    vector<StringMeeting> result = calendarMatching(calendar1, dailyBounds1, calendar2, dailyBounds2, meetingDuration);
    display(result);
    return 0;
}

vector<StringMeeting> calendarMatching(vector<StringMeeting> calendar1, StringMeeting dailyBounds1, vector<StringMeeting> calendar2, StringMeeting dailyBounds2, int meetingDuration){
    vector<Meeting> updatedCalendar1 = updateCalendar(calendar1, dailyBounds1);
    vector<Meeting> updatedCalendar2 = updateCalendar(calendar2, dailyBounds2);
    vector<Meeting> mergedCalendar = merge(updatedCalendar1, updatedCalendar2);
    vector<Meeting> flattenedCalendar = flatten(mergedCalendar);
    return getMatching(flattenedCalendar, meetingDuration);
}

vector<Meeting> updateCalendar(vector<StringMeeting> calendar, StringMeeting dailyBounds){
    vector<StringMeeting> updatedCalendar;
    updatedCalendar.push_back({"0:00", dailyBounds.start});
    updatedCalendar.insert(updatedCalendar.end(), calendar.begin(), calendar.end());
    updatedCalendar.push_back({dailyBounds.end, "23:59"});
    
    vector<Meeting> calendarInMinutes;
    for(int i = 0; i < updatedCalendar.size(); i++)
        calendarInMinutes.push_back({timeToMinutes(updatedCalendar[i].start), timeToMinutes(updatedCalendar[i].end)});
    return calendarInMinutes;
}

vector<Meeting> merge(vector<Meeting> calendar1, vector<Meeting> calendar2){
    vector<Meeting> merged;
    int i = 0, j = 0;
    while(i < calendar1.size() && j < calendar2.size()){
        Meeting meeting1 = calendar1[i];
        Meeting meeting2 = calendar2[j];
        if(meeting1.start < meeting2.start){
            merged.push_back(meeting1);
            i++;
        }else{
            merged.push_back(meeting2);
            j++;
        }
    }
    
    while(i < calendar1.size())
        merged.push_back(calendar1[i++]);
    while(j < calendar2.size())
        merged.push_back(calendar2[j++]);
    
    return merged;
}

vector<Meeting> flatten(vector<Meeting> calendar){
    vector<Meeting> flattened = {calendar[0]};
    for(int i = 1; i < calendar.size(); i++){
        Meeting current = calendar[i];
        Meeting prev = flattened[flattened.size() - 1];
        if(current.start < prev.end)
            flattened[flattened.size() - 1] = {prev.start, max(current.end, prev.end)};
        else flattened.push_back(current);
    }
    return flattened;
}

vector<StringMeeting> getMatching(vector<Meeting> calendar, int meetingDuration){
    vector<Meeting> matching;
    for(int i = 1; i < calendar.size(); i++){
        int start = calendar[i - 1].end;
        int end = calendar[i].start;
        int duration = end - start;
        if(duration >= meetingDuration)
            matching.push_back({start, end});
    }
    
    vector<StringMeeting> matchingString;
    for(int i = 0; i < matching.size(); i++)
        matchingString.push_back({minutesToTime(matching[i].start), minutesToTime(matching[i].end)});
    
    return matchingString;
}

int timeToMinutes(string time){
    int delimiterPos = time.find(":");
    int hours = stoi(time.substr(0, delimiterPos));
    int minutes = stoi(time.substr(delimiterPos + 1, time.length()));
    return hours * 60 + minutes;
}

string minutesToTime(int minutes){
    int hours = minutes / 60;
    int mins = minutes % 60;
    string hoursString = to_string(hours);
    string minsString = mins < 10 ? "0" + to_string(mins) : to_string(mins);
    return hoursString + ":" + minsString;
}

void display(vector<StringMeeting> array){
    for(int i = 0; i < array.size(); i++)
        cout << array[i].start << "-" << array[i].end << endl;
}
