inherit __DIR__"binghuodao";

void create()
{
        set("short", "����ɽ��");
        set("long",
"����һ�����صĶ�Ѩ������ͨϿ���ڵĶ�Ѩһ���������Ե�ʮ\n"
"�ֿ���ȴ���쳣��ʪ����������ճ������ɫ��Һ�壬����ͺ��\n"
"������������˲���������\n"
);
        set("exits", ([ 
                "northwest"   : __DIR__"guanmulin1", 
                "southwest"   : __DIR__"guanmulin2",
                "east"   : __DIR__"cangbaodong",
        ]));
        
        set("outdoors", 0);
        
        set("n_time", 60);
        set("n_npc",1);
        set("n_max_npc", 2);
        set("s_npc", __DIR__"npc/jiutoulong");  
        setup();
}
