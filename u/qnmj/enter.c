inherit ROOM; 
void create() 
{ 
        set("short", "����Ǳ��"); 
        set("long", @LONG 
�˴���Ǳ���ؾ�������֮�ء�
LONG
); 
                        
        set("outdoors", "qnjm1"); 
        set("virtual_room", 1); 
        set("exits", ([ 
                "out" : "/d/city/guangchang", 
        ])); 
        set("objects",([
                "/d/maze/qnmj/npc/1": 5,
        ])); 
        setup();
        replace_program(ROOM); 
} 
