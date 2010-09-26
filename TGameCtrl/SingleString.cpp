#include "SinglelineString.h"

CSinglelineString::CSinglelineString(){ }
CSinglelineString::~CSinglelineString(){ }
void CSinglelineString::set_string(const char* msg, const RECT& rect, int ifont){ }
void CSinglelineString::set_rect(const RECT& rect){ }
void CSinglelineString::set_color(DWORD color){ }
void CSinglelineString::set_format(DWORD format){ }

const char* CSinglelineString::get_string(){ return 0; }
const RECT&	CSinglelineString::get_rect(){ return RECT(); }

void CSinglelineString::draw(){ }
bool CSinglelineString::is_ellipsis(){ return 0; }
bool CSinglelineString::empty(){ return 0; }
void CSinglelineString::clear(){ }