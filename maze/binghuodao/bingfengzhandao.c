inherit __DIR__"binghuodao";

void create()
{
        set("short", "����ջ��");
        set("long",
"�����ǿ���Ͽ�ȵ�һ��ջ����ֻ��ջ������һ�������������\n"
"�ɡ���ѩ���죬ǰ��һƬãã���ƺ���������ͷ��\n"
);
        set("exits", ([ 
                "south"   : __DIR__"bingfenggu", 
                "north"   : __DIR__"bingxuexiagu",
        ]));
        set("n_time", 30);
        set("n_npc",1);
        set("n_max_npc", 4);
        set("s_npc", __DIR__"npc/binglangren");
        
        setup();
}
