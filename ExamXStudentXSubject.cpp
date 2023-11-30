#include "ExamXStudentXSubject.h"

ExamXStudentXSubject::ExamXStudentXSubject() {

};
ExamXStudentXSubject::ExamXStudentXSubject(int firstResourceId, int secondResourceId, int thirdResourceId) {
    setFirstResourceId(firstResourceId);
    setSecondResourceId(secondResourceId);
    setAttendance(true);
};
int ExamXStudentXSubject::getFirstResourceId() const {
    return _firstResourceId;
};
int ExamXStudentXSubject::getSecondResourceId() const {
    return _secondResourceId;
};
int ExamXStudentXSubject::getThirdResourceId() const {
    return _thirdResourceId;
};
bool ExamXStudentXSubject::getAttendance() const {
    return _attendance;
};
bool ExamXStudentXSubject::getState() const {
    return _state;
};
void ExamXStudentXSubject::setFirstResourceId(int firstResourceId) {
    _firstResourceId = firstResourceId;
};
void ExamXStudentXSubject::setSecondResourceId(int secondResourceId) {
    _secondResourceId = secondResourceId;
};
void ExamXStudentXSubject::setThirdResourceId(int thirdResourceId) {
    _thirdResourceId = thirdResourceId;
};
void ExamXStudentXSubject::setAttendance(bool attendance) {
    _attendance = attendance;
};
void ExamXStudentXSubject::setState(bool state) {
    _state = state;
};