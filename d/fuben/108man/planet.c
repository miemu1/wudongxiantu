inherit ROOM; 
void create() 
{ 
        set("short", "��ɽ��"); 
        set("long", @LONG 
��������ɽ������
LONG
); 
                        
  //      set("outdoors", "yxl4"); 
        set("virtual_room", 1); 
        set("exits", ([ 
                "south" : "/d/fuben/108man/enter", 
        ])); 
        setup();
        replace_program(ROOM); 
} 
int is_jfb() { return 1; }
