inherit ROOM; 
void create() 
{ 
        set("short", "���"); 
        set("long", @LONG 
��������ɽ����ڡ���
LONG
); 
                        
        set("virtual_room", 1); 
        set("exits", ([ 
                "north" : "/d/fuben/108/planet", 
        ])); 
        setup();
        replace_program(ROOM); 
} 
int is_jfb() { return 1; }