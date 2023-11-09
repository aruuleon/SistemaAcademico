#include <cstring>
#include "SubjectXComission.h"

SubjectXComission::SubjectXComission() {

};
SubjectXComission::SubjectXComission(std::string comissionCode, int subjectId, int numberOfExams) {
    setComissionCode(comissionCode);
    setSubjectId(subjectId);
    setNumberOfExams(numberOfExams);
    setAssignedTime(true);
};
std::string SubjectXComission::getComissionCode() const {
    return _comissionCode;
};
int SubjectXComission::getSubjectId() const {
    return _subjectId;
};
int SubjectXComission::getNumberOfExams() const {
    return _numberOfExams;
};
bool SubjectXComission::getAssignedTime() const {
    return _assignedTime;
};
void SubjectXComission::setComissionCode(std::string comissionCode) {
    strcpy(_comissionCode, comissionCode.c_str());
};
void SubjectXComission::setSubjectId(int subjectId) {
    _subjectId = subjectId;
};
void SubjectXComission::setNumberOfExams(int numberOfExams) {
    _numberOfExams = numberOfExams;
};
void SubjectXComission::setAssignedTime(bool assignedTime) {
    _assignedTime = assignedTime;
};