inherit __DIR__"binghuodao";

void create()
{
        set("short", "����ʯ��");
        set("long",
"������λ�ڻ���ȵ��һ�Ͽ��֮���һ��ʯ�š������ݲ�����\n"
"̧ͷ֮�䣬��������ʯ����Ż���׹������ʱȴ����˾޴�Ļ�\n"
"�򣬰����ž޴�����죬�ض�ɽҡ�����˾����Ѷ���\n"
);
        set("exits", ([ 
                "north"   : __DIR__"huoyangu",
                "south"   : __DIR__"liehuoxiagu",
        ]));
        set("n_time", 30);
        set("n_npc",1);
        set("n_max_npc", 4);
        set("s_npc", __DIR__"npc/jinsefenghuang");
        
        setup();
}
