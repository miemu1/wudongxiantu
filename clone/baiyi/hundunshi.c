/*
����ǿ��ϵͳ��˼·����������������ֻ����Σ����뱾��򵥣���Ҫһ�����߼��ԡ�
*/

#include <ansi.h>
inherit COMBINED_ITEM;
string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void setup()
{
	set_amount(1);
	::setup();
}

//int query_autoload() { return 1; }
void create()
{
        set_name(HIM "����ʯ" NOR, ({ "hundun shi", "fqhs" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIM "�������ʯ���Խ��������װ�����еȽ���������Ȼ��Ҫ���װ������һ����ǿ�Ȳſ���ʹ������"NOR"\n");
                set("unit", "��");
                set("base_unit", "��");
                set("base_weight", 1);
                set("zb",1);             
                set("yuanbao",100);               
            set("base_value",500000);
        }
        setup();
}

void init()
{
        add_action("do_integrate", "fstrengthen");
}

int do_integrate(string arg)
{
        object me;
        object ob;
        string ownerid,namejia;
        int cgl,cgll;

        if (! arg)
                return notify_fail("��Ҫ��ʲô������ʹ�û���ʯ��\n");

        me = this_player();
        if (! objectp(ob = present(arg, me)) &&
            ! objectp(ob = present(arg, environment(me))))
                return notify_fail("�����Ϻ͸���û���������߰���\n");
if (ob->is_weapon() || ob->is_unarmed_weapon())
                return notify_fail("��ֻ���ڷ�����ʹ�û���ʯ��\n");
        ownerid = ob->item_owner();
//jiapoint = ob->query("point")/10;
cgl = ob->apply_armor()/10;//���ŷ�����Чֵ����ߣ�ǿ�����Ѷ�Ҳ���
tell_object(me, "���" + name() + "����" + ob->name() + "�ϣ�Ȼ����������дʣ�\n"
                        "ֻ������ʯ������" + ob->name() + "���ڣ�\n");
if (ob->query("itemlevel")>=20)
{
tell_object(me, HIC "�㷢�ֻ���ʯ�Ѿ��޷�����" + ob->name() +" �ֻ��������˳�����\n" NOR);
return 1;
}
if (random(cgl)==0||me->query("sitemlevel")>=cgl)//�����ʲô��˼�أ���˼�����б��ף��������ǿ��ʧ��
{
        ob->add("itemlevel", 1);
        ob->save();
        ob->set("armor_prop/armor",ob->apply_armor());//��ȡ
        me->delete("sitemlevel");
        if (ob->query("itemlevel")==20)
                message("channel:chat",HBRED"ϵͳͨ��"HIR"��"+me->query("name")+"�ɹ���"+ob->name()+"ǿ������������һ����װ��������.\n"NOR,users());                
        tell_object(me, HIC "ǿ���ɹ�������ܵ�" + ob->name() + HIC"��ĸ����ض������ˣ�Ŀǰ�Ƚף�+"+ob->query("itemlevel")+"��\n" NOR);
    
        }
        else
        {
        me->add("sitemlevel",1);
        tell_object(me, HIC "ǿ��ʧ�ܣ����" + ob->name() + HIC"ɶ�仯��û�У�\n" NOR);           
        }
add_amount(-1);
      
        return 1;
}