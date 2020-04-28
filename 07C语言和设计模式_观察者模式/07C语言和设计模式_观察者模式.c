/*hdr
**  Copyright ...
**  AUTHOR              MichaelMa
**  DATE                4-May-2014
**  DESCRIPTION         implement a mode of observer in C
**  NOTE                may be some bugs             
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
/***************************DEFINES************************************/
#define MAX_LIST_CNT	10
#define MAX_ID_LEN		256
 
/*
	zero members
*/
#define ZERO(TYPE,instance)	struct TYPE instance;	\
			instance.TYPE##_constructor = TYPE##_constructor;	\
			instance.TYPE##_constructor(&instance);	\
/***************************TYPEDEFS**********************************/
typedef struct _Observer* List;
 
struct _Observer
{
	char ID[MAX_ID_LEN];
	void (*_Observer_constructor)(struct _Observer*);
	void (*_Observer_destructor)(struct _Observer*);
	void (*_Observer_Update)(struct _Observer*);
};
 
struct _Fire
{
	unsigned short m_nObserverCnt;
	List m_listObservers[MAX_LIST_CNT];
	void (*_Fire_constructor)(struct _Fire*);
	void (*_Fire_destructor)(struct _Fire*);
	void (*_Fire_Notify)(struct _Fire*);
	void (*_Fire_AddObserver)(struct _Fire*,void* pElement);
	void (*_Fire_DelObserver)(struct _Fire*,void* pElement);
};
 
/****************************FUNCTIONS**********************************/
void _Observer_Update(struct _Observer* pThis)
{
	printf("%s\n",pThis->ID);
}
 
void _Observer_destructor(struct _Observer* pThis)
{
	
}
 
void _Observer_constructor(struct _Observer* pThis)
{
	memset(pThis->ID,0,sizeof(pThis->ID));
	pThis->_Observer_Update = _Observer_Update;
	pThis->_Observer_destructor = _Observer_destructor;
}
 
void _Fire_Notify(struct _Fire* pThis)
{
	unsigned short uIter = 0;
	pThis = pThis;
	for( ; uIter < pThis->m_nObserverCnt ; ++uIter)
	{
		(pThis->m_listObservers[uIter])->_Observer_Update(pThis->m_listObservers[uIter]);
	}
}
 
void _Fire_AddObserver(struct _Fire* pThis,void* pElement)
{
	if(pThis->m_nObserverCnt < MAX_LIST_CNT)
	{
		pThis->m_listObservers[pThis->m_nObserverCnt] = (List)pElement;
		++(pThis->m_nObserverCnt);
	}
	else
	{
		printf("list is full now!\n");
	}
}
 
void _Fire_DelObserver(struct _Fire* pThis,void* pElement)
{	
	unsigned short uIter = 0;
	unsigned short uInnerIter = 0;	
	for( ; uIter < pThis->m_nObserverCnt ; uIter++)
	{		
		if(pThis->m_listObservers[uIter] == pElement)
		{
			--(pThis->m_nObserverCnt);		
			for(uInnerIter =  uIter; uInnerIter < (pThis->m_nObserverCnt - uIter) ; uInnerIter++)
			{
				pThis->m_listObservers[uInnerIter] = pThis->m_listObservers[uInnerIter + 1];
			}
			pThis->m_listObservers[pThis->m_nObserverCnt] = NULL;
			break;
		}
	}
}
 
void _Fire_destructor(struct _Fire* pThis)
{
 
}
 
void _Fire_constructor(struct _Fire* pThis)
{
	pThis->m_nObserverCnt = 0;
	memset(pThis->m_listObservers,0,sizeof(pThis->m_listObservers));
	pThis->_Fire_Notify = _Fire_Notify;
	pThis->_Fire_AddObserver = _Fire_AddObserver;
	pThis->_Fire_DelObserver = _Fire_DelObserver;
	pThis->_Fire_destructor = _Fire_destructor;
}
 
 
int main(void)
{
	printf("init...\n");
 
	ZERO(_Observer,obs1);
	strcpy(obs1.ID,"MichaelMa");
	ZERO(_Observer,obs2);
	strcpy(obs2.ID,"ZhangZhan");
	ZERO(_Observer,obs3);
	strcpy(obs3.ID,"ChenFeng");
	ZERO(_Observer,obs4);
	strcpy(obs4.ID,"LuoJi");
 
 
 
	ZERO(_Fire,fire);
 
	fire._Fire_AddObserver(&fire,&obs1);
 
	fire._Fire_AddObserver(&fire,&obs2);
 
	fire._Fire_AddObserver(&fire,&obs3);
 
	fire._Fire_AddObserver(&fire,&obs4);
 
	fire._Fire_Notify(&fire);
	printf("----------------------------\n");
	fire._Fire_DelObserver(&fire,&obs1);
 
	fire._Fire_Notify(&fire);
 
	printf("----------------------------\n");
	fire._Fire_AddObserver(&fire,&obs1);
 
	fire._Fire_Notify(&fire);
 
	printf("finished...!\n");
 
	return 0;
}
