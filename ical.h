class ical
{
public:
  void printEvent(int year, int month, int day, std::string name, std::string time);
  std::string getMonth(int month);
  std::string getDate();
  FILE* getFile(std::string url);
  std::string url(std::string ufile);
};
