inherit __DIR__"binghuodao";

void create()
{
        set("short", "��ѩϿ����");
        set("long",
"·�ľ�ͷ��Ȼ��һ���޴��Ͽ�ȣ����ܱ����ʵ�ɽ���Χ��ɽ\n"
"���ֱ����Ļ�ѩ���ǣ���ʱ���������޴�ĺ�У�Ͽ��֮���ƺ�\n"
"���ž޴�����ޡ�\n"
);
        set("exits", ([ 
                "south"   : __DIR__"bingfengzhandao", 
        ]));
        set("n_time", 30);
        set("n_npc",1);
        set("n_max_npc", 2);
        set("s_npc", __DIR__"npc/binglong");
        
        setup();
}
