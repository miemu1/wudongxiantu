
#include <ansi.h>
inherit BAOXIANG_ITEM;

void create()
{
        set_name(HIM"�Ͻ�ѫ������"NOR,({"xiang"}));
        //���һ��Ҫ���ã�
        set("BAOXIANG_LIST",([
                "/clone/goods/study-emblem":300,   //��Ʒ�ļ���:����
                "/clone/goods/learn-emblem":200,   //��Ʒ�ļ���:����
                "/clone/goods/practice-emblem":150,   //��Ʒ�ļ���:����
                "/clone/goods/derive-emblem":150,   //��Ʒ�ļ���:����
                "/clone/goods/research-emblem":100,   //��Ʒ�ļ���:����
                "/clone/goods/research-emblem2":50,   //��Ʒ�ļ���:����
        ])); //��������1000��Ϊ�������Ҽ���ĸ����ܺ�Ϊ1000�����ʴ�ĳ��ּ��ʸߡ�����
        
        set("long", HIY "����һֻ��ɫ�ı��䣬װ�ε���ⱦ�����������Դ򿪣�open������\n" NOR); 
        set("unit", "Щ");
        set("base_unit", "��");
        set("no_give",1);
        set("no_drop",1);
        set("base_weight",1);
        set("base_value",1);
        set_amount(1); //��Ϊ�Ǹ�combined��Ʒ �������һ��Ҫ���ã���Ȼ�����

}
void init()
{
        add_action("do_open","open"); //���ʹ�õĽӿ� ����������std��
        add_action("do_test","test"); //������ʦ������ ����ok��ע�ʹ���
}

