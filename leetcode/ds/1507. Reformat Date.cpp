class Solution {
public:
    vector<string> split(string input) {
        stringstream ss(input);
        string tmp;
        vector<string>res;
        while(getline(ss,tmp, ' ')) {
            res.push_back(tmp);
        }
        return res;
    }
    string reformatDate(string date) {
        vector <string> dateInfo = split(date);
        map <string, string> monthMap, dayMap;

        monthMap["Jan"] = "01", monthMap["Feb"] = "02", monthMap["Mar"] = "03", monthMap["Apr"] = "04";
        monthMap["May"] = "05", monthMap["Jun"] = "06", monthMap["Jul"] = "07", monthMap["Aug"] = "08";
        monthMap["Sep"] = "09", monthMap["Oct"] = "10", monthMap["Nov"] = "11", monthMap["Dec"] = "12";
        
        dayMap["1st"] = "01", dayMap["2nd"] = "02", dayMap["3rd"] = "03", dayMap["4th"] = "04", dayMap["5th"] = "05";
        dayMap["6th"] = "06", dayMap["7th"] = "07", dayMap["8th"] = "08", dayMap["9th"] = "09", dayMap["10th"] = "10";
        dayMap["11th"] = "11", dayMap["12th"] = "12", dayMap["13th"] = "13", dayMap["14th"] = "14", dayMap["15th"] = "15";
        dayMap["16th"] = "16", dayMap["17th"] = "17", dayMap["18th"] = "18", dayMap["19th"] = "19", dayMap["20th"] = "20";
        dayMap["21st"] = "21", dayMap["22nd"] = "22", dayMap["23rd"] = "23", dayMap["24th"] = "24", dayMap["25th"] = "25";
        dayMap["26th"] = "26", dayMap["27th"] = "27", dayMap["28th"] = "28", dayMap["29th"] = "29", dayMap["30th"] = "30";
        dayMap["31st"] = "31";

        string day = dayMap[dateInfo[0]];
        string month = monthMap[dateInfo[1]];
        string year = dateInfo[2];
        return year + "-" + month + "-" + day;
    }
};