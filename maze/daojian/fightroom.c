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
       
        set("exits", ([ 
                "out": "/d/city/wumiao",
        ])); 

        
        set("objects", ([
                __DIR__"npc/hu-yidao" : 1,
                __DIR__"npc/miao-renfeng" : 1,
        ]));
        
        setup(); 
} 

