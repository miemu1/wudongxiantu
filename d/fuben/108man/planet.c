inherit ROOM; 
void create() 
{ 
        set("short", "梁山伯"); 
        set("long", @LONG 
这里是梁山伯…。
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
