#include <iostream>
#include <memory>
using namespace std;

struct Record {
  string patientName;

  Record(string patientName) : patientName(patientName) {}
};

struct Doctor {
  string name;
  shared_ptr<Record> record;

  Doctor(string name) : name(name) {}

  void accessRecord(shared_ptr<Record> record) {
    this->record = record;
    cout << name << " is accessing " << record->patientName << endl;
  }

  void finish() {
    if(record) {
      cout << name << " is finished with " << record->patientName << endl;

      if (record.use_count() == 1) {
        cout << "Patient record deleted from the system." << record->patientName << endl;
      }

      record.reset();
    }
  }
};

int main() {
  Doctor d1 = Doctor("Bob");
  Doctor d2 = Doctor("Joe");
  Doctor d3 = Doctor("Jill");
  shared_ptr<Record> record(new Record("Susan"));
  d1.accessRecord(record);
  d2.accessRecord(record);
  d3.accessRecord(record);
  record.reset();
  d1.finish();
  d2.finish();
  d3.finish();
}