inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
���Ƕ����ϵ�һ���Ӳݴ�������С·��������ƽʱûʲ
ô�˼���·�߿��Ų�֪��Ұ��������������Ȼ�ߴ�ͦ�Ρ�����
͸�����յ��������ǰ߲߰�����Ӱ�ӡ�
LONG );
        set("exits", ([
                "east"      : "/d/lingzhou/xuanhebao",
                "westup"    : __DIR__"shanjiao",
                 //"north"   : __DIR__"jingji/enter",
        ]));

        set("outdoors", "xuanming");
        setup();
        replace_program(ROOM);
}
