
inherit "/inherit/room/house_base";

void create()
{
    set("short", "������");
    set("long", @LONG
�˴�������һ���족��������������ľ�����Գ�һ�֡���ȸ����
�ּ䣬��Ȫ�������⡣����ǳ���������ɣ�һ������С������ͨ����
����������ϡ��һ����ש���ߵĴ�լԺ����Ϊĳ�����פ��֮
���ڡ�
LONG);

    set("exits",
    ([
        "east"  : "/d/emei/taohua-wu",
    ]));

    set("outdoors", "emei");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
