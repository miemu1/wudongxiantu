// jingangfuyuan.c

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name(HIW"��ָ�ԭʯ"NOR, ({"jingangfuyuan shi", "shi"}));
	set_weight(5);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "��������Ѿ���������װ�����ԣ����ã�\n");
		set("base_unit", "��");
		set("base_value", 10000);
		set("no_lose",1);
		set("yuanbao", 500);
		set("base_weight", 1);
	}
	set("action_list", ([
		"ʹ��" : "updurable2",
	]));
	set_amount(1);
	setup();
}

void init()
{
    if ( environment() == this_player() )
		add_action("do_updurable", "updurable2");
}

int do_updurable(string arg)
{
	object me, ob, obj;
	
	object *inv; 
	string str, type, yns, obname;
	mapping list;
	string *list_sx,qb;
	int i;
	
	me = this_player();
	ob = this_object();

	if ( environment(ob) != me )
		return 0;

	if (!arg || sscanf(arg, "%s %s", type, obname) != 2)
	{
		inv = all_inventory(me);
		if (sizeof(inv) > 0) {
			str = "";
			for(i = 0; i < sizeof(inv); i++)
			{
				if (inv[i]->query("id") == "mengmian yi")
					continue;
				if ( inv[i]->query("jianding")) 
				{
					str += sprintf("%s", 
								inv[i]->query("name") + ":updurable2 " + file_name(this_object()) 
																	+ " " + file_name(inv[i]) ) + ZJSEP;
				}
			}
			 if (str!="")
				tell_object(me, ZJOBLONG + "\n"+ZJOBACTS2+ZJMENUF(3,3,9,30) + str+"\n");
			 else
				tell_object(me, ZJOBLONG+"�Ҳ����Ѿ�������װ����\n");
		}
		return 1;
	} else if (sscanf(arg, "%s %s %s", type, obname, yns) != 3){		
		if (!objectp(obj = present(obname, me)))
			return notify_fail("������û�����װ����\n");	
		
		if (obj->query("id") == "mengmian yi")
			return notify_fail("����Ϊ���װ��ȥ���������ԡ�\n");	
		
		if (!present(type, me))
			return notify_fail("������û������������\n");	
		
		if ( !obj->query("jianding") ) //ֻ���Ǽ�������װ��
			return notify_fail("���װ����û�м��������ԡ�\n");	
		
		if (!yns) {
			str = sprintf("%s", "ȷ�����:updurable2 " + type + " " + obname + " yes" + ZJSEP);
			str += sprintf("%s", "ȡ������:updurable2 " + type + " " + obname + " no");
			tell_object(me, ZJOBLONG + "\n"+ZJOBACTS2+ZJMENUF(3,3,9,30) + str+"\n");
			return 1;
		}
	} else {		
		if (yns == "no")
		{
			tell_object(me, "��ȡ���˲�����\n");
			return 1;
		}	
		if (!objectp(obj = present(obname, me)))
			return notify_fail("������û�����װ����\n");	
		
		if (obj->query("id") == "mengmian yi")
			return notify_fail("����Ϊ���װ��ȥ���������ԡ�\n");	
		
		if (!present(type, me))
			return notify_fail("������û������������\n");	
		
		if ( !list=obj->query("jianding") ) //ֻ���Ǽ�������װ��
			return notify_fail("���װ����û�м��������ԡ�\n");	
			
		if (sizeof(list)>0)
		{
			obj->unequip();
			
			if (obj->query("weapon_prop")) {
				qb = "weapon_prop";
			} else {
				qb = "armor_prop";
			}
			list_sx = keys(list);
			str ="";
			for(i=0;i<sizeof(list_sx);i++)
			{
				if (obj->query(qb+"/"+list_sx[i])) {
					obj->add(qb+"/"+list_sx[i], -list[list_sx[i]]);
					str +=qb+"/"+list_sx[i]+","+list[list_sx[i]] +"  ";
				}
			}
			obj->delete("jianding");
			obj->set("ok_jianding", 1);
			
			tell_object(me, sprintf("��ϲ��Ϊ%sȥ�������м������ԡ�\n", obj->name()));
			
			log_file( "cut_jianding", sprintf("%s -->%s ȥ���������Գɹ���(%s)%s\n",
											me->name() + "(" + geteuid(me) + ")", obj->name(), str, ctime(time())) );
			
			ob->add_amount(-1);
		}
		return 1;
	} 
}