#include "DAO/AttributesDAO.h"

int main(){
	AttributesDAO daoAttr=AttributesDAO();
	daoAttr.parseAttributes("csv/attributes.csv");
}
