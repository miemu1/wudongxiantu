inherit __DIR__"binghuodao";

void create()
{
        set("short", "�ر���");
        set("long",
"������һ������Ķ�Ѩ���Ĵ��Ƕ��Ѱ׹ǣ��ƺ���������������\n"
"��֪�Ӻδ���������ͳ��ĺ���������ë���Ȼ��\n"
);
        set("exits", ([ 
                "west"   : __DIR__"shenmishandong",
        ]));
        
        set("outdoors", 0);
        
        set("n_time", 30);
        set("n_npc",1);
        set("n_max_npc", 2);
        set("s_npc", __DIR__"npc/bianyijiutoulong");
                
        setup();
}
