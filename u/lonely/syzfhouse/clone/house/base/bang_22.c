
inherit "/inherit/room/house_base";

void create()
{
    set("short", "�����ض�");
    set("long", @LONG
���Ǽ����ض��׵Ļ���ɽ�𡣵Ͱ��Ĺ�ľ�Ĵ�ɢ������Ҳ������
Щ���ס�վ�ڴ˴������������عس�¥����ʣ�Ρ��׳�ۡ�������ȥ
������һ���ֺ��ׯԺ�����ƽ������ĸ�����פ�����ڡ�
LONG);

    set("exits",
    ([
        "west"  : "/d/xiyu/jiayu-guan",
    ]));

    set("outdoors", "xiyu");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
