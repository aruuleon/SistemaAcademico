#include "SubjectXCareer.h"

SubjectXCareer::SubjectXCareer() {

};
SubjectXCareer::SubjectXCareer(int subjectId, int careerId) {
   setSubjectId(subjectId);
   setCareerId(careerId);
   setState(true);
};
int SubjectXCareer::getSubjectId() const {
    return _subjectId;
};
int SubjectXCareer::getCareerId() const {
    return _careerId;
};
bool SubjectXCareer::getState() const {
    return _state;
};
void SubjectXCareer::setSubjectId(int subjectId) {
    _subjectId = subjectId;
};
void SubjectXCareer::setCareerId(int careerId) {
    _careerId = careerId;
};
void SubjectXCareer::setState(bool state) {
    _state = state;
};