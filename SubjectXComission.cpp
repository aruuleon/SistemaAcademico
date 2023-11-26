#include <cstring>
#include "SubjectXComission.h"

SubjectXComission::SubjectXComission() {

};
SubjectXComission::SubjectXComission(int subjectId, int comissionId) {
    setSubjectId(subjectId);
    setComissionId(comissionId);
    setState(true);
};
int SubjectXComission::getComissionId() const {
    return _comissionId;
};
int SubjectXComission::getSubjectId() const {
    return _subjectId;
};
bool SubjectXComission::getState() const {
    return _state;
};
void SubjectXComission::setComissionId(int comissionId) {
    _comissionId = comissionId;
};
void SubjectXComission::setSubjectId(int subjectId) {
    _subjectId = subjectId;
};
void SubjectXComission::setState(bool state) {
    _state = state;
};