inherit ROOM; 

void create() 
{ 
        set("short", "森林出口"); 
        set("long", @LONG 
原始森林树叶苍黑如盖，遮天蔽日，林中弥漫着枯叶腐烂
和树脂混合的味道，地上的苔鲜落叶踩上去软绵绵的，上面还
布满野兽的痕迹，四周浓密的山雾，让人难以分辨方向。
LONG
); 
                        
        set("outdoors", "forest"); 
        set("no_magic",1);
        set("exits", ([ /* sizeof() == 3 */ 
                "out": "/d/city/guangchang",
        ])); 

                        
        setup();
        // replace_program(ROOM); 
} 


