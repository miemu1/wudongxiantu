inherit __DIR__"binghuodao";

void create()
{
        set("short", "Ͽ��");
        set("long",
"������һ��ƽ����Ͽ�ȣ�Ͽ������ǰ�У�����������ͷ������\n"
"���˾�����ǣ�Ͽ�ȱ��˴�ݲ������϶�ȴ��ľïʢ��ͬһϿ��ȴ\n"
"������������ľ������Ƿ�����˼��\n"
);
        set("exits", ([ 
                "west"   : __DIR__"xiagu2", 
        ]));
        set("n_time", 30);
        set("n_npc",1);
        set("n_max_npc", 4);
        set("s_npc", __DIR__"npc/yeren");       
        setup();
}
