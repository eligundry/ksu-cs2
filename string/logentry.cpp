#include "logentry.h"

////////////////////////////////////////////////////////// 
// PRE: string is a line from log file
// POST: LogEntry object is given values from line of input file
//
LogEntry::LogEntry(String s)
{
        
	std::vector<String> vec = s.split(' ');
	
	if (vec.size() == 10) {
		host = vec[0];

		// split vec[3] on a colon to start with
		
		std::vector<String> date_time = vec[3].split(':');
		//date_time has four strings date_time[0] contains date
		//date_time[1] = hour, date_time[2] = minute, 
		//date_time[3] = second
		
		std::vector<String> date_string = date_time[0].split('/');
		//date_string has three strings date_string[0] contains day,
		//date_string[1] = month, date_string[2] = year

		String stringday = date_string[0].substr(1, date_string[0].length());
		date.setday(stringday);
		//sets the day equal to the substring of date_string[0]
		//i.e. "[18"; from position 1 to length of string
		//takes into account if day is single digit

		String stringmonth = date_string[1];
		date.setmonth(stringmonth);

		int intyear = date_string[2].to_i();
		date.setyear(intyear);
			
		time.sethour(date_time[1].to_i());
		time.setminute(date_time[2].to_i());
		time.setsecond(date_time[3].to_i());
		
		request = vec[5] + vec[6] + vec[7];

		status = vec[8];
		
		if (vec[9] == '-') {
			number_of_bytes = 0;
		}
		
		number_of_bytes = vec[9].to_i();
	} else {
		host = "";
		date.setday("");
		date.setmonth("");
		date.setyear(0);
		time.sethour(0);
		time.setminute(0);
		time.setsecond(0);
		request = "";
		status = "";
		number_of_bytes = 0;
     }
	
}

////////////////////////////////////////////////////////// 
// PRE: If in is a file input stream, then in has already been connected
// to a file.  
// POST: vector<LogEntry> result is filled with LogEntry's from lines of
// istream
//
std::vector<LogEntry> parse(std::istream& in)
{
	std::vector<LogEntry> result;	

	do {
		String line = getline(in);
		LogEntry log(line);
		result.push_back(log);
	} while (!in.eof());

	return result;
}

////////////////////////////////////////////////////////////
// PRE: If out is a file output stream, then out has already been connected to a file.
// POST: outputs a LogEntry object to the screen
//
std::ostream& operator<<(std::ostream& out, const LogEntry& log)
{
	out << "Host: " << log.host << '\n';
	
	out << "Day: " << log.date.getday() << '\n';
	out << "Month: " << log.date.getmonth() << '\n';
	out << "Year: " << log.date.getyear() << '\n';
	
	out << "Hour: " << log.time.gethour() << '\n';
	out << "Minute: " << log.time.getminute() << '\n';
	out << "Second: " << log.time.getsecond() << '\n';
	
	out << "Request: " << log.request << '\n';
	out << "Status: " << log.status << '\n';
	out << "Bytes: " << log.number_of_bytes << "\n\n";

	return out;
}

////////////////////////////////////////////////////////// 
// PRE: If out is a file output stream, then out has already been
// connected to a file.
// POST: Outputs each LogEntry to the output stream specified
//
void output_all(std::ostream& out, const std::vector<LogEntry> & vec_o_logs)
{
    for (unsigned int i = 0; i < vec_o_logs.size(); ++i) {
		out << vec_o_logs[i];
	}
}

////////////////////////////////////////////////////////// 
// PRE:  If out is a file output stream, then out has already been
// connected to a file.  logs has been given values
// POST: outputs the host of each LogEntry object in logs vector
//
void by_host(std::ostream& out, const std::vector<LogEntry>& logs)
{
	for (unsigned int i = 0; i < logs.size(); ++i) {
		out << logs[i].gethost() << '\n';
	}
}

////////////////////////////////////////////////////////// 
// PRE:  logs has been given values
// POST: returns the sum of number_of_bytes of each LogEntry object in 
// logs vector
//
int byte_count(const std::vector<LogEntry> & logs)
{
    int sum = 0;

    for (unsigned int i = 0; i < logs.size(); ++i) {
		sum += logs[i].getbytes();
	}

    return sum;
}
