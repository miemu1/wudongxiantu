inherit __DIR__"binghuodao";

void create()
{
        set("short", "�һ�Ͽ����");
        set("long",
"��������Ѿ������ô����������������������л����\n"
"ҫ��������������ʱ��������գ�����һ������Ȼ��һ���޴������\n"
"�����Ż��档�����ɹ����������������Ļ�ʯ������¡���\n"
);
        set("exits", ([ 
                "north"   : __DIR__"huoyanshiqiao",
        ]));
        set("n_time", 30);
        set("n_npc",1);
        set("n_max_npc", 4);
        set("s_npc", __DIR__"npc/huolong");
        
        setup();
}
