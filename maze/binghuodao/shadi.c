inherit __DIR__"binghuodao";

void create()
{
        set("short", "ɳ��");
        set("long",
"������һƬɳ�أ����ɺ�̲�ľ��˳�ˢ���ɡ�Ȼ������ɳ���ϣ�\n"
"ȴ�о��ӽ��Ĵ��������������ƺ���ɳ�������̲���ʲô������\n"
);
        set("exits", ([ 
                "west"    : __DIR__"haitan", 
                "north"   : __DIR__"haitan1", 
                "south"   : __DIR__"haitan2", 
                "east"    : __DIR__"guanmucong", 
        ]));


        set("n_time", 30);
        set("n_npc",1);
        set("n_max_npc", 4);
        set("s_npc", __DIR__"npc/chihuoshe");

        setup();
}
