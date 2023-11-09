#include <cstring>
#include "StudentXSubject.h"

StudentXSubject::StudentXSubject() {

};
StudentXSubject::StudentXSubject(std::string comissionCode, int studentId, int subjectId) {
    setComissionCode(comissionCode);
    setStudentId(studentId);
    setSubjectId(subjectId);
};
std::string StudentXSubject::getComissionCode() const {
    return _comissionCode;
};
int StudentXSubject::getStudentId() const {
    return _studentId;
};
int StudentXSubject::getSubjectId() const {
    return _subjectId;
};
void StudentXSubject::setComissionCode(std::string comissionCode) {
    strcpy(_comissionCode, comissionCode.c_str());
};
void StudentXSubject::setStudentId(int studentId) {
    _studentId = studentId;
};
void StudentXSubject::setSubjectId(int subjectId) {
    _subjectId = subjectId;
};