inherit __DIR__"binghuodao";

void create()
{
        set("short", "��ľ��");
        set("long",
"��˵�������������ɵ��ķ�����������������Ƕ������뿪��\n"
"�����Ǳ���������̲�������Ĵ��ź��߾�ʯ����Χ��һ���޼ʵ�\n"
"�󺣣����ߴ�������޴�����죬�ض�ɽҡһ�㣬�ƺ����ϵĻ�ɽ\n"
"�ڲ��ϵ��緢���ͷų��޴��������\n"
);
        set("exits", ([ 
                "west"   : __DIR__"shenbingtan", 
                "southeast"   : __DIR__"shenmishandong",
        ]));

        set("n_time", 30);
        set("n_npc",1);
        set("n_max_npc", 4);
        set("s_npc", __DIR__"npc/shixueyeren");
                
        setup();
}
