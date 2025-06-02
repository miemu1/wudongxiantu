// store.c
// by jjyy

#include <ansi.h>
inherit ITEM;
inherit F_SAVE;

mapping baowus;

void create()
{
	set_name(HIW"�����"NOR, ({ "chuwu dai" }) );
	set("long",HIW"һ������Ĵ��ӣ����Դ�ȡ��౦����"NOR"\n");
	set("unit", "��");
	set("no_lose", 1);
	set("no_save", 1);
	set("no_get", 1);
	set("no_put", 1);
	set("no_give", 1);
	set("no_drop", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	seteuid(getuid());
}

string query_save_file()
{
	string id;

	if( !stringp(id = query("owner_id")) || id != this_player()->query("id")) return 0;

	return sprintf(DATA_DIR"baibao/%c/%s", id[0], id);
}

int set_owner(string id)
{
	set("owner_id", id);
	return 1;
}

void init()
{
	if(!query("owner_id") || query("owner_id") != this_player()->query("id"))
	{
		set_owner(this_player()->query("id"));
	}

	if(this_player()->query("id")==query("owner_id"))
	{
		restore();
	}
}

varargs int do_store(string arg, int index)
{
	object me,ob;
	string *item_nb,nb;
	int i, snum;
	mapping info=([]);
	string type;

	me = this_player();
	if(!arg)
	{
		write("��Ҫ������д�ʲô��Ʒ��\n");
		return 1;
	}

	if(!objectp(ob=present(arg,me)))
	{
		write("������û��������Ʒ�ɣ�\n");
		return 1;
	}

//������Ʒ���ܱ���
	if (ob->query("unique") || ! clonep(ob) )
	{
		tell_object(me, ob->name() + "���ܴ����ڴ����\n");
		return 1;
	}

//װ������Ʒ���ܱ���
	switch((string)ob->query("equipped")) 
	{
	case "worn":
		tell_object(me, ob->name() + "���������������ܴ�š�\n");
		return 1;
	case "wielded":
		tell_object(me, ob->name() + "�����Ƚ��װ�����ܴ�š�\n");
		return 1;
	}

//�ں���Ʒ��������Ʒ���ܱ���
	if (sizeof(all_inventory(ob))) 
	{
		tell_object(me, "�����Ȱ�" + ob->query("name") + "����Ķ������ó�����\n");
		return 1;
	}

	if (ob->is_character()) 
	{
		tell_object(me, "�����һ�������Ӳ���������\n");
		return 1;
	}

	if (ob->query("money_id"))
	{
		tell_object(me, "��Ǯ�Ļ����ǵ�Ǯׯȥ�ɣ�\n");
		return 1;
	}
	if (ob->query("no_cun"))
	{
		tell_object(me, "������������Ʒ�������޷����棡\n");
		return 1;
	}
	if (ob->is_corpse()) 
	{
		tell_object(me, "�ⶫ��������ᷢ���İɣ�\n");
		return 1;
	}
//������Լ�����಻�ܱ�����Ʒ���ж�
//////ʬ�壬����ȵȡ�����

	if(!clonep(ob)
	||ob->query("unique")
	||ob->query("treasure")
	||ob->query("owner")
	||ob->query("no_put")
	||ob->query("u_times")
	||ob->query("quest")
	||ob->is_corpse()
	||ob->query("food_remaining")
	||ob->query("liquid")
	||ob->query("material")=="meat"
	||ob->query("money_id")
	||ob->is_character()
	||(stringp(ob->query("owner")) && ob->query("owner")!="0")
	||ob->query("credit")
	) {
		tell_object(me, "����������ܴ��봢�����\n");
		return 1;
	}
	snum = 20 + me->query("zjvip/all_pay")/10 + me->query("combat_exp")/50000;
	if (snum>100) snum=100;

	if (mapp(baowus)&&(sizeof(keys(baowus))>=snum)) {
		tell_object(me, "��Ĵ�����Ѿ��Ų��¸�����Ʒ�ˣ��Ͻ�����һ�°ɡ�\n");
		return 1;
	}
	
	if (!index && ob->query_amount()) {
		write(INPUTTXT("��������"+ob->name()+NOR"��������","mystore put "+file_name(ob)+" $txt# ")+"\n");
		return 1;
	}
	if (index && index > ob->query_amount()) {
		tell_object(me, "������û����ô������\n");
		return 1;
	}
	if (index && index < 1){
		tell_object(me, "��������������ȷ��\n");
		return 1;
	}
	
	if(ob->query("weapon_prop"))
		type="����";
	else if(ob->query("armor_prop"))
		type="����";
	else
		type="�ӻ�";
	
	info["short"] = ob->query("name");
	
	if (index) {
		info["base_unit"] = ob->query("base_unit");
		info["amount"] = index;
	} 
	
	info["id"] = ob->parse_command_id_list();
	info["file"] = base_name(ob);
	info["type"] = type;
	info["data"] = save_variable(ob->query_entire_dbase());

	if( !mapp(baowus)) baowus = ([]);
	if( baowus == ([]))
	{
		baowus["1"] = info;
		if (index)
			ob->add_amount(-index);
		else
			destruct(ob);
		save();
	}
	else
	{
		item_nb = sort_array( keys(baowus), (: strcmp :) );
		for(i=1; i<(sizeof(item_nb)+2); i++) {
			nb = sprintf("%d",i);
			
			if (index && baowus[nb] && baowus[nb]["file"] == info["file"] && baowus[nb]["amount"] > 0) {
				baowus[nb]["amount"] += index;
				tell_object(me,"���"+ob->query("name") + "������"+(index?index:1)+"������˴��ӣ�\n");
				log_file("baibao/cun", sprintf("%-24s%-40s%s\n", 
							me->name() + "("+me->query("id")+")", 
								"����"+filter_color(ob->name())+"("+ob->query("id")+")����:"+(index?index:1), ctime(time())));
				if (index)
					ob->add_amount(-index);
				else
					destruct(ob);
				break;
			}
			else
			if(undefinedp(baowus[nb]))
			{
				baowus[nb] = info;
				tell_object(me,"���"+ob->query("name") + "����˴��ӣ�\n");
				log_file("baibao/cun", sprintf("%-24s%-40s%s\n", 
							me->name() + "("+me->query("id")+")", 
								"����"+filter_color(ob->name())+"("+ob->query("id")+")����:"+(index?index:1), ctime(time())));
				if (index)
					ob->add_amount(-index);
				else
					destruct(ob);
				break;
			}
			/*
			baowus = ([]);
			*/
		}
		save();
	}
	me->save();
	if(!index && objectp(ob))
		tell_object(me,"��Ʒ����ʧ�ܣ�\n");
	else
		tell_object(me,"��Ʒ����ɹ���\n");
	me->force_me("mystore put");
	return 1;
}
string long()
{
	object me = this_player();
	tell_object(me, ZJFORCECMD("mystore"));
	return "";
}

varargs int get_item(string arg, int index)
{
	object me,ob;
	string *item_nb;
	int i;

	me = this_player();

	if( !mapp(baowus) || baowus==([]))
	{
		write("��Ĵ�����ûʲô������ȡ�ġ�\n");
		return 1;
	}
	if(!arg)
	{
		write("��Ҫ�Ӵ�����ȡ��ʲô��Ʒ��\n");
		return 1;
	}

	if(undefinedp(baowus[arg]))
	{
		write("��Ĵ�����ûû�������ŵ���Ʒ��\n");
		return 1;
	}

	if (!index && baowus[arg]["amount"] > 0) {
		write(INPUTTXT("������ȡ����������","mystore get "+arg+" $txt# ")+"\n");
		return 1;
	} 
		
	if (index && index < 1){
		tell_object(me, "����ȡ����������ȷ��\n");
		return 1;
	}
		
	if (index && baowus[arg]["amount"] < index)
	{
		tell_object(me, "������ﲢû�д����ô��������\n");
		return 1;
	}
	
	ob = new(baowus[arg]["file"]);
	if (!ob)
	{
		tell_object(me, "������������Ʒ�ļ��Ѿ���ʧ������ϵ��ʦ��\n");
		return 1;
	}
	ob->set_dbase(restore_variable(baowus[arg]["data"]));
	ob->set_name(baowus[arg]["short"],baowus[arg]["id"]);
	if (index && baowus[arg]["amount"])
		ob->set_amount(index);
	tell_object(me,"���"+ob->query("name")+"�Ӵ�����ȡ����\n");

	if(ob->move(me))
	{
		if (index && baowus[arg]["amount"] > index)
		{
			baowus[arg]["amount"] -= index;
		} else
			map_delete(baowus, arg);
		me->save();
		save();
		tell_object(me,"��Ʒȡ���ɹ���\n");
		log_file("baibao/qu", sprintf("%-24s%-40s%s\n", 
					me->name() + "("+me->query("id")+")", 
						"ȡ��"+filter_color(ob->name())+"("+ob->query("id")+")����:"+(index?index:1), ctime(time())));
	}
	else
		tell_object(me,"��Ʒȡ��ʧ�ܣ�\n");
	me->force_me("mystore");
	return 1;
}

int query_item(string arg)
{
	object me;
	string *item_nb;
	string *msg, ob_name, type, name;
	int ye, yeall, j, i;
	string str,line;

	me = this_player();

	if( !mapp(baowus) )
	{
		write("��Ŀǰû�д���κ���Ʒ�ڴ����\n");
		return 1;
	}

	item_nb = sort_array( keys(baowus), (: strcmp :) );

	if( sizeof(item_nb)<1 )
	{
		write("��Ŀǰû�д���κ���Ʒ�ڴ����\n");
		return 1;
	}
	msg = ({});
	if (!arg)
		arg = "ȫ�� 1";
	
	if( sscanf(arg, "%s %s %d", type, name, ye) != 3)
		if( sscanf(arg, "%s %d", type, ye) != 2) {
			write("��Ҫ�鿴ʲô��\n");
			return 1;
		}
		
	for (i = 0; i < sizeof(item_nb); i++) 
	{
		if (type == "ȫ��" || type == baowus[item_nb[i]]["type"] 
			|| (type == "����" && strsrch(baowus[item_nb[i]]["short"], name) != -1))
		{
			ob_name = baowus[item_nb[i]]["short"];
					
			if (baowus[item_nb[i]]["amount"] /*&& baowus[item_nb[i]]["base_unit"]*/)
				ob_name = baowus[item_nb[i]]["amount"] +"" + (baowus[item_nb[i]]["base_unit"] ? baowus[item_nb[i]]["base_unit"] : "��")+ ob_name;
			else
			if(baowus[item_nb[i]]["unit"])
				ob_name = baowus[item_nb[i]]["unit"] + ob_name;
			
			line = sprintf("%s:%s", ob_name,"mystore get "+item_nb[i]);
			msg += ({ line, });
		}
	}

	if(msg==({})) {
		write("û����Ҫ�ҵ���Ʒ��\n");
		return 1;
	}
	msg -=({0});
	str = ZJOBLONG+sprintf("�����С�%s������Ʒ��(%d��)��"+"\n", name ? name : type+"����", sizeof(msg));
	str += ZJOBACTS2+ZJMENUF(2,2,9,30);

	yeall = sizeof(msg)/20;
	if(sizeof(msg)%20) yeall += 1;
	if(ye<1) ye = 1;
	if(ye>yeall) ye = yeall;
	j = (ye-1)*20;
	i = ye*20;
	if (i >= sizeof(msg)) i = sizeof(msg);
	i--;
	if(yeall>1)
		str += "��һҳ:mystore "+type+" "+(ye-1)+ZJSEP"��һҳ("+(ye)+"/"+(yeall)+"):mystore "+type+" "+(ye+1)+ZJSEP;
	str += implode(msg[j..i], ZJSEP);

	write(str+"\n");
	return 1;
}	
int query_autoload() { return 1; }
