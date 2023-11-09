#include <cstring>
#include "TeacherXSubject.h"

TeacherXSubject::TeacherXSubject() {

};
TeacherXSubject::TeacherXSubject(std::string comissionCode, int teacherId, int subjectId) {
    setComissionCode(comissionCode);
    setTeacherId(teacherId);
    setSubjectId(subjectId);
};
std::string TeacherXSubject::getComissionCode() const {
    return _comissionCode;
};
int TeacherXSubject::getTeacherId() const {
    return _teacherId;
};
int TeacherXSubject::getSubjectId() const {
    return _subjectId;
};
void TeacherXSubject::setComissionCode(std::string comissionCode) {
    strcpy(_comissionCode, comissionCode.c_str());
};
void TeacherXSubject::setTeacherId(int teacherId) {
    _teacherId = teacherId;
};
void TeacherXSubject::setSubjectId(int subjectId) {
    _subjectId = subjectId;
};