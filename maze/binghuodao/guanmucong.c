inherit __DIR__"binghuodao";

void create()
{
        set("short", "��ľ��");
        set("long",
"Ũ�ܵĹ�ľ�ԣ�����ʱ�˵������ڴ˴����ƺ����ܵ���һЩ��\n"
"��Ļ�����Ӱ�죬��ľ������Լ��ʲô��ֵ��춯��\n"
);
        set("exits", ([ 
                "west"    : __DIR__"shadi", 
                "east"    : __DIR__"xiagu1", 
        ]));

        set("n_time", 30);
        set("n_npc",1);
        set("n_max_npc", 4);
        set("s_npc", __DIR__"npc/juxingshanzhu");
                
        setup();
}
