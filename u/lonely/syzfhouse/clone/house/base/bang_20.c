
inherit "/inherit/room/house_base";

void create()
{
    set("short", "������");
    set("long", @LONG
�����Ǿ�����Ļ�ԭ�յأ��������䳤��Щ��ľ�ݲݡ���Զ����
һ�Ÿߴ�ͦ���İ������������󱱷��У��·�������֦ͷ��Ҷɳɳ��
�졣���������ֳ�һ����լԺ��ٲȻ�ǽ������ĸ�����פ�ء�
LONG);

    set("exits",
    ([
        "east"  : "/d/shanhai-guan/junzheng",
    ]));

    set("outdoors", "shanhai-guan");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
