inherit __DIR__"binghuodao";

void create()
{
        set("short", "�����");
        set("long",
"������ڵض�ɽҡ���ƺ���δƽ��������Զ��������С��ɽ��\n"
"���ȿֺ���緢�ţ�˭Ҳ����ͣ�µ����ӡ������������ڣ�������\n"
"�����ܣ����˵��������Ļ����ǿ϶��Ǿ���ǧ��������ľ��֡�\n"
);
        set("exits", ([ 
                "east"   : __DIR__"shenghuotai", 
                "west"   : __DIR__"huoyangu",
        ]));
        set("n_time", 30);
        set("n_npc",1);
        set("n_max_npc", 4);
        set("s_npc", __DIR__"npc/huohu");               
        setup();
}
