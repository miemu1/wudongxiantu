inherit ROOM; 

void create() 
{ 
        set("short", "���"); 
        set("long", @LONG 
������BOSS��ս����

LONG
); 
                        
        set("outdoors", "boss"); 
        set("no_magic",1);
        set("exits", ([ /* sizeof() == 3 */ 
                "out": "/d/city/wumiao",
        ])); 
        
        set("objects", ([
                CLASS_D("misc/jianling") : 1,
        ]));
        
        setup(); 
} 

