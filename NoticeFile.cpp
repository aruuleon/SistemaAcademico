#include "NoticeFile.h"
#include <cstring>

NoticeFile::NoticeFile(){

};
NoticeFile::NoticeFile(std::string fileName){
    strcpy(_fileName, fileName.c_str());
};
Notice NoticeFile::read(int position){
    Notice notice;
    FILE *p = fopen(_fileName, "rb");
    if(p == nullptr){
        return notice;
    }
    fseek(p, position * sizeof(Notice), SEEK_SET);
    fread(&notice, sizeof(Notice), 1, p);
    fclose(p);
    return notice;
};
int NoticeFile::searchRecord(int noticeCode){
    int position = 0;
        Notice notice;
        FILE *p = fopen(_fileName, "rb");
        if(p == nullptr){
        return -1;
        }
        while(fread(&notice, sizeof(Notice), 1, p)) {
            if(notice.getCode() == noticeCode) {
                fclose(p);
                return position;
            }
            position++;
        }
    fclose(p);
    return -1;
};
int NoticeFile::numberOfRecords(){
    FILE *p = fopen(_fileName, "rb");
    if(p == nullptr){
        return -1;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Notice);
};
bool NoticeFile::numberOfActiveRecords(){
    FILE * p = fopen(_fileName, "rb");
    if(p == nullptr){
        return false;
    }
    int numberOfRecords = this->numberOfRecords();
    int position = 0;
    bool activeRecord = false;
    while(!activeRecord && position < numberOfRecords) {
        Notice notice = this->read(position);
        if(notice.getState()) {
            activeRecord = true;
        }
        position++;
    }
    return activeRecord;
};
bool NoticeFile::save(const Notice& notice){
    bool successfulSave = false; //guardado exitoso
    FILE * p = fopen(_fileName, "ab");
    if(p == nullptr) {
        return successfulSave;
    }
    successfulSave  = fwrite(&notice, sizeof(Notice), 1, p);    
    fclose(p);
    return successfulSave;
};
bool NoticeFile::save(const Notice& notice, int position){
    bool successfulSave = false;
    FILE * p = fopen(_fileName, "rb+");
        if(p == nullptr) {
            return successfulSave;
        }
    fseek(p, position * sizeof(Notice), SEEK_SET);
    successfulSave = fwrite(&notice, sizeof(Notice), 1, p);
    fclose(p);
    return successfulSave;
};
bool NoticeFile::deleteRecord(int codeNotice){
    int position = searchRecord(codeNotice);
    Notice notice = read(position);
    notice.setState(false);
    return save(notice, position);
};
bool NoticeFile::addOrDelete(int codeNotice, int action){
    int position = searchRecord(codeNotice);
    if(position != -1) {
        Notice notice = read(position);
        if(action == 1){
            notice.setState(true);
        } else {
            notice.setState(false);
        }
        return save(notice, position);
    } else {
        return false;
    }
};