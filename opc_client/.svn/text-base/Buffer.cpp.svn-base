//---------------------------------------------------------------------------


#pragma hdrstop

#include "Buffer.h"

#pragma package(smart_init)

Buffer::Buffer(){ 
}

Buffer::~Buffer(){
}
string Buffer::getTime(){
        return lpszString;
}
void Buffer::setTime(string time){
        lpszString = time;
}
string Buffer::getActiveTime(){
        return lpszActiveString;
}
void Buffer::setActiveTime(string time){
        lpszActiveString = time;
}
string Buffer::getQualityStr(){
        return qldStr;
}
void Buffer::setQualityStr(string qualidade){
        qldStr = qualidade;
}
unsigned short Buffer::getQuality(){
        return qld;
}
void Buffer::setQuality(unsigned short qualidade){
        qld = qualidade;
}
string Buffer::getMessage(){
        return szMsg;
}
void Buffer::setMessage(string msg){
       szMsg = msg;
}
string Buffer::getSource(){
        return szSrc;
}
void Buffer::setSource(string src){
        szSrc = src;
}
string Buffer::getCMaskStr(){
        return changeMaskSrt;
}
void Buffer::setCMaskStr(string cm){
        changeMaskSrt = cm;
}

unsigned short Buffer::getCMask(){
        return changeMask;
}
void Buffer::setCMask(unsigned short cm){
        changeMask = cm;
}
string Buffer::getNewStateStr(){
        return newStateStr;
}
void Buffer::setNewStateStr(string ns){
        newStateStr = ns;
}
unsigned short Buffer::getNewState(){
        return newState;
}
void Buffer::setNewState(unsigned short ns){
        newState = ns;
}
string Buffer::getEventTypeStr(){
        return evTypeStr;
}
void Buffer::setEventTypeStr(string et){
        evTypeStr = et;
}
unsigned short Buffer::getEventType(){
        return evType;
}
void Buffer::setEventType(unsigned short et){
        evType = et;
}
string Buffer::getEventCategory(){
        return evCategory;
}
void Buffer::setEventCategory(string ec){
        evCategory = ec;
}
string Buffer::getSeverity(){
        return severity;
}
void Buffer::setSeverity(string sev){
        severity = sev;
}
string Buffer::getCondName(){
        return conditionName;
}
void Buffer::setCondName(string cn){
        conditionName = cn;
}
string Buffer::getSubCondName(){
        return subConditionName;
}
void Buffer::setSubCondName(string scn){
        subConditionName = scn;
}
bool Buffer::getAckRequired(){
        return ackRequired;
}
void Buffer::setAckRequired(bool ar){
        ackRequired = ar;
}
string Buffer::getAckRequiredString(){
        return ackRequiredStr;
}
void Buffer::setAckRequiredString(string ars){
        ackRequiredStr = ars;
}
string Buffer::getactorID(){

        if (actorID == ""){
            return " ";
        }else{
            return actorID;
        }
}
void Buffer::setactorID(string aID){
        actorID = aID;
}
string Buffer::getNomeSub(){
        return nomeSub;
}
void Buffer::setNomeSub(string nome){
        nomeSub = nome;
}
void Buffer::setCookie(int c){
    cookie = c;
}
int Buffer::getCookie(){
    return cookie;
}
void Buffer::setAttr(string *attr, int qnt){

    qntAtrr = qnt;

    for (int i=0;i<qntAtrr;i++){
        attributos[i] = attr[i];
    }

}
void Buffer::getAttr(string *listaAttr){

    for (int i=0;i<qntAtrr;i++){
        listaAttr[i] = attributos[i];
    }
}

int Buffer::getQntAttr(){
    return qntAtrr;
}
//---------------------------------------------------------------------------


