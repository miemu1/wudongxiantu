// �ٺ� /clone/eat/food/bai_he.c
// by lala, 1997-12-16

inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name( "�ٺ�", ({"bai he","lily"}) );
    set_weight( 30000 );
    if ( clonep() )
            set_default_object( __FILE__ );
    else {
        set( "long", @LONG
���������İٺϣ��ųơ�̫��֮�Ρ���Ӫ����Ϊ�ḻ��������ҩ��
LONG
        );


        set( "unit", "��" );
        set( "value", 300 + random( 500 ) );
        set( "food_remaining", 2 );
        set( "food_supply", 25 );
    }
}

