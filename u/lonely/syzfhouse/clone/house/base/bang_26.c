
inherit "/inherit/room/house_base";

void create()
{
    set("short", "ɽ��ݵ�");
    set("long", @LONG
�˼�λ��ʯ�������ࡣ������ȥ��һƬ���֮�е�׺�����ǵ��
��Ұ������۰׻���ƻ�g�ϻ��̺죬ɷ�Ǻÿ���һ�����߷�ǽ��ɽ
ׯ���ڲݵ�һͷ�������ǽ������ĸ�����פ�����ڡ�
LONG);

    set("exits",
    ([
        "east"  : "/d/taishan/shijin",
    ]));

    set("outdoors", "taishan");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
