inherit ROOM; 
void create() 
{ 
        set("short", "入口"); 
        set("long", @LONG 
这里是梁山伯入口…。
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