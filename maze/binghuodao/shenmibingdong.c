inherit __DIR__"binghuodao";

void create()
{
        set("short", "���ر���");
        set("long",
"���Ǳ��������ص�һ�������������ڱ�׶�ݺᣬ�����쳣��\n"
);
        set("exits", ([ 
                "east"   : __DIR__"shenmibingdong2", 
                "north"   : __DIR__"shenmibingdong3",
                "south"   : __DIR__"xuanwutai",
        ]));
        
        set("outdoors", 0);
        
        set("n_time", 30);
        set("n_npc",1);
        set("n_max_npc", 4);
        set("s_npc", __DIR__"npc/bingjiangshi");        
        setup();
}
