// time.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string str;
	mapping my;
	my = me->query_entire_dbase();
	
	if(!arg)
	{
		str =ZJOBLONG+HBWHT "��""��������������"HIC"���ɾ���"HBWHT"����������������" "��" NOR"\n";
		str+="Ŀǰ�������磺"HIM+my["wudao"]+NOR"\n";
		str +=ZJOBACTS2+ZJMENUF(1,1,10,30);
		str += HBWHT"��""��������������"HIR"������������"HBWHT"����������������"  "��"NOR":xiulians1 -a"ZJSEP;
		str += HBWHT"��""��������������"HIR"������������"HBWHT"����������������"  "��"NOR":xiulians1 -b"ZJSEP;
		str += HBWHT"��""��������������"HIR"������������"HBWHT"����������������"  "��"NOR":xiulians1 -c"ZJSEP;
		str += HBWHT"��""��������������"HIR"������������"HBWHT"����������������"  "��"NOR":xiulians1 -d"ZJSEP;
		str += HBWHT"��""��������������"HIR"��������Բ��"HBWHT"����������������"  "��"NOR":xiulians1 -e"ZJSEP;

		str += HBWHT"��""��������������"HIR"������������"HBWHT"����������������"  "��"NOR":xiulians1 -f"ZJSEP;
		str += HBWHT"��""��������������"HIR"������������"HBWHT"����������������"  "��"NOR":xiulians1 -g"ZJSEP;
		str += HBWHT"��""��������������"HIR"������������"HBWHT"����������������"  "��"NOR":xiulians1 -h"ZJSEP;
		str += HBWHT"��""��������������"HIR"������������"HBWHT"����������������"  "��"NOR":xiulians1 -i"ZJSEP;
		str += HBWHT"��""��������������"HIR"��������Բ��"HBWHT"����������������"  "��"NOR":xiulians1 -j"ZJSEP;

		str += HBWHT"��""��������������"HIR"�𵤾�������"HBWHT"����������������"  "��"NOR":xiulians1 -k"ZJSEP;
		str += HBWHT"��""��������������"HIR"�𵤾�������"HBWHT"����������������"  "��"NOR":xiulians1 -l"ZJSEP;
		str += HBWHT"��""��������������"HIR"�𵤾�������"HBWHT"����������������"  "��"NOR":xiulians1 -m"ZJSEP;
		str += HBWHT"��""��������������"HIR"�𵤾�������"HBWHT"����������������"  "��"NOR":xiulians1 -n"ZJSEP;
		str += HBWHT"��""��������������"HIR"�𵤾���Բ��"HBWHT"����������������"  "��"NOR":xiulians1 -o"ZJSEP;

		str += HBWHT"��""��������������"HIR"ԪӤ��������"HBWHT"����������������"  "��"NOR":xiulians1 -p"ZJSEP;
		str += HBWHT"��""��������������"HIR"ԪӤ��������"HBWHT"����������������"  "��"NOR":xiulians1 -q"ZJSEP;
		str += HBWHT"��""��������������"HIR"ԪӤ��������"HBWHT"����������������"  "��"NOR":xiulians1 -r"ZJSEP;
		str += HBWHT"��""��������������"HIR"ԪӤ��������"HBWHT"����������������"  "��"NOR":xiulians1 -s"ZJSEP;
		str += HBWHT"��""��������������"HIR"ԪӤ����Բ��"HBWHT"����������������"  "��"NOR":xiulians1 -t"ZJSEP;

		str += HBWHT"��""��������������"HIR"���Ͼ�������"HBWHT"����������������"  "��"NOR":xiulians1 -u"ZJSEP;
		str += HBWHT"��""��������������"HIR"���Ͼ�������"HBWHT"����������������"  "��"NOR":xiulians1 -v"ZJSEP;
		str += HBWHT"��""��������������"HIR"���Ͼ�������"HBWHT"����������������"  "��"NOR":xiulians1 -w"ZJSEP;
		str += HBWHT"��""��������������"HIR"���Ͼ�������"HBWHT"����������������"  "��"NOR":xiulians1 -x"ZJSEP;
		str += HBWHT"��""��������������"HIR"���Ͼ���Բ��"HBWHT"����������������"  "��"NOR":xiulians1 -y"ZJSEP;

		str += HBWHT"��""��������������"HIR"���񾳡�����"HBWHT"����������������"  "��"NOR":xiulians1 -z"ZJSEP;
		str += HBWHT"��""��������������"HIR"���񾳡�����"HBWHT"����������������"  "��"NOR":xiulians1 -1"ZJSEP;
		str += HBWHT"��""��������������"HIR"���񾳡�����"HBWHT"����������������"  "��"NOR":xiulians1 -2"ZJSEP;
		str += HBWHT"��""��������������"HIR"���񾳡�����"HBWHT"����������������"  "��"NOR":xiulians1 -3"ZJSEP;
		str += HBWHT"��""��������������"HIR"���񾳡�Բ��"HBWHT"����������������"  "��"NOR":xiulians1 -4"ZJSEP;

		str += HBWHT"��""��������������"HIR"���徳������"HBWHT"����������������"  "��"NOR":xiulians1 -5"ZJSEP;
		str += HBWHT"��""��������������"HIR"���徳������"HBWHT"����������������"  "��"NOR":xiulians1 -6"ZJSEP;
		str += HBWHT"��""��������������"HIR"���徳������"HBWHT"����������������"  "��"NOR":xiulians1 -7"ZJSEP;
		str += HBWHT"��""��������������"HIR"���徳������"HBWHT"����������������"  "��"NOR":xiulians1 -8"ZJSEP;
		str += HBWHT"��""��������������"HIR"���徳��Բ��"HBWHT"����������������"  "��"NOR":xiulians1 -9"ZJSEP;

		str += HBWHT"��""��������������"HIR"��˾�������"HBWHT"����������������"  "��"NOR":xiulians1 -10"ZJSEP;
		str += HBWHT"��""��������������"HIR"��˾�������"HBWHT"����������������"  "��"NOR":xiulians1 -11"ZJSEP;
		str += HBWHT"��""��������������"HIR"��˾�������"HBWHT"����������������"  "��"NOR":xiulians1 -12"ZJSEP;
		str += HBWHT"��""��������������"HIR"��˾�������"HBWHT"����������������"  "��"NOR":xiulians1 -13"ZJSEP;
		str += HBWHT"��""��������������"HIR"��˾���Բ��"HBWHT"����������������"  "��"NOR":xiulians1 -14"ZJSEP;

		str += HBWHT"��""��������������"HIR"�ɽپ�������"HBWHT"����������������"  "��"NOR":xiulians1 -15"ZJSEP;
		str += HBWHT"��""��������������"HIR"�ɽپ�������"HBWHT"����������������"  "��"NOR":xiulians1 -16"ZJSEP;
		str += HBWHT"��""��������������"HIR"�ɽپ�������"HBWHT"����������������"  "��"NOR":xiulians1 -17"ZJSEP;
		str += HBWHT"��""��������������"HIR"�ɽپ�������"HBWHT"����������������"  "��"NOR":xiulians1 -18"ZJSEP;
		str += HBWHT"��""��������������"HIR"�ɽپ���Բ��"HBWHT"����������������"  "��"NOR":xiulians1 -19"ZJSEP;

		message("vision", str+"\n", me);
		return 1;
	}
	else if(arg=="-a"){
		object where;
		where = environment(me);		
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/a"))
			return notify_fail("���Ѿ��ɹ�ͻ���������������š�\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");
		if (! where->query("sleep_room"))
			return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");
		if ((int)me->query("potential") - me->query("learned_points") < 10000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 100)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");	
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("gain/2ap",5);
			me->add("gain/2dp",5);
			me->add("gain/break",5);
			me->add("gain/armor",5);
			me->add("jingjie",1);
			me->add("potential",-10000);
			me->add("yuanbao",-100);
			me->set("jingjie/a",1);
			me->set("wudao","������������");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�������������ţ�����˱���,����,����,�Ƽ��������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());			
	return 1;
	}
	else if(arg=="-b"){
			object where;
			where = environment(me);
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/b"))
			return notify_fail("���Ѿ��ɹ�ͻ���������������ڡ�\n");	
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");
		if (! where->query("sleep_room"))
			return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");
		if (me->query("potential") - me->query("learned_points") < 10000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 100)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");	
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");
		if (!me->query("jingjie/a"))
			return notify_fail("�㾳��δ�������������ţ�����Ⱦָ�����������ڣ�����\n");
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("gain/2ap",5);
			me->add("gain/2dp",5);
			me->add("gain/break",5);
			me->add("gain/armor",5);
			me->set("jingjie/b",1);
			me->add("potential",-10000);
			me->add("yuanbao",-100);
			me->set("wudao","������������");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�������������ڣ�����˱���,����,����,�Ƽ��������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());
			
	return 1;
	}
	else if(arg=="-c"){
				object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/c"))
			return notify_fail("���Ѿ��ɹ�ͻ���������������ڡ�\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");
		if (! where->query("sleep_room"))
			return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");	
		if (me->query("potential") - me->query("learned_points") < 10000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 100)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");
		if (!me->query("jingjie/b"))
			return notify_fail("�㾳��δ�������������ڣ�����Ⱦָ�����������ڣ�������\n");	
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("gain/2ap",5);
			me->add("gain/2dp",5);
			me->add("gain/break",5);
			me->add("gain/armor",5);
			me->set("jingjie/c",1);
			me->add("potential",-10000);
			me->add("yuanbao",-100);
			me->set("wudao","������������");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�������������ڣ�����˱���,����,����,�Ƽ��������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());			
	return 1;
	}
	else if(arg=="-d"){
			object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/d"))
			return notify_fail("���Ѿ��ɹ�ͻ���������������ڡ�\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");	
		if (! where->query("sleep_room"))
			return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");	
		if (me->query("potential") - me->query("learned_points") < 10000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 100)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");		
		if (!me->query("jingjie/c"))
			return notify_fail("�㾳��δ�������������ڣ�����Ⱦָ�����������ڣ�������\n");			
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("gain/2ap",5);
			me->add("gain/2dp",5);
			me->add("gain/break",5);
			me->add("gain/armor",5);
			me->set("jingjie/d",1);
			me->add("potential",-10000);
			me->add("yuanbao",-100);
			me->set("wudao","������������");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�������������ڣ�����˱���,����,����,�Ƽ��������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());			
	return 1;
	}
	else if(arg=="-e"){
			object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/e"))
			return notify_fail("���Ѿ��ɹ�ͻ������������Բ����\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");	
		if (! where->query("sleep_room"))
			return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");	
		if (me->query("potential") - me->query("learned_points") < 10000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 100)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");				
		if (!me->query("jingjie/d"))
			return notify_fail("�㾳��δ�������������ڣ�����Ⱦָ��������Բ����������\n");
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("gain/2ap",5);
			me->add("gain/2dp",5);
			me->add("gain/break",5);
			me->add("gain/armor",5);
			me->set("jingjie/e",1);
			me->add("potential",-10000);
			me->add("yuanbao",-100);
			me->set("wudao","��������Բ��");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ����������Բ��������˱���,����,����,�Ƽ��������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());			
	return 1;
	}
	else if(arg=="-f"){
		object where;
		where = environment(me);		
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/f"))
			return notify_fail("���Ѿ��ɹ�ͻ���������������š�\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");
		if (! where->query("sleep_room"))
			return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");
		if ((int)me->query("potential") - me->query("learned_points") < 20000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 150)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");	
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");
		if (!me->query("jingjie/e"))
			return notify_fail("�㾳��δ����������Բ��������Ⱦָ�����������ţ�����\n");
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("gain/2ap",5);
			me->add("gain/2dp",5);
			me->add("gain/break",5);
			me->add("gain/armor",5);
			me->add("potential",-20000);
			me->add("yuanbao",-150);
			me->set("jingjie/f",1);
			me->set("wudao","������������");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�������������ţ�����˱���,����,����,�Ƽ��������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());			
	return 1;
	}
	else if(arg=="-g"){
			object where;
			where = environment(me);
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/g"))
			return notify_fail("���Ѿ��ɹ�ͻ���������������ڡ�\n");	
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");
		if (! where->query("sleep_room"))
			return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");
		if (me->query("potential") - me->query("learned_points") < 20000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 150)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");	
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");
		if (!me->query("jingjie/f"))
			return notify_fail("�㾳��δ�������������ţ�����Ⱦָ�����������ڣ�����\n");
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("gain/2ap",5);
			me->add("gain/2dp",5);
			me->add("gain/break",5);
			me->add("gain/armor",5);
			me->set("jingjie/f",1);
			me->add("potential",-20000);
			me->add("yuanbao",-150);
			me->set("wudao","������������");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�������������ڣ�����˱���,����,����,�Ƽ��������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());
			
	return 1;
	}
	else if(arg=="-h"){
				object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/h"))
			return notify_fail("���Ѿ��ɹ�ͻ���������������ڡ�\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");
		if (! where->query("sleep_room"))
			return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");	
		if (me->query("potential") - me->query("learned_points") < 20000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 150)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");
		if (!me->query("jingjie/f"))
			return notify_fail("�㾳��δ�������������ڣ�����Ⱦָ�����������ڣ�������\n");	
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("gain/2ap",5);
			me->add("gain/2dp",5);
			me->add("gain/break",5);
			me->add("gain/armor",5);
			me->set("jingjie/h",1);
			me->add("potential",-20000);
			me->add("yuanbao",-150);
			me->set("wudao","������������");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�������������ڣ�����˱���,����,����,�Ƽ��������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());			
	return 1;
	}
	else if(arg=="-i"){
			object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/i"))
			return notify_fail("���Ѿ��ɹ�ͻ���������������ڡ�\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");	
		if (! where->query("sleep_room"))
			return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");	
		if (me->query("potential") - me->query("learned_points") < 20000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 150)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");		
		if (!me->query("jingjie/h"))
			return notify_fail("�㾳��δ�������������ڣ�����Ⱦָ�����������ڣ�������\n");			
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("gain/2ap",5);
			me->add("gain/2dp",5);
			me->add("gain/break",5);
			me->add("gain/armor",5);
			me->set("jingjie/i",1);
			me->add("potential",-20000);
			me->add("yuanbao",-150);
			me->set("wudao","������������");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�������������ڣ�����˱���,����,����,�Ƽ��������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());			
	return 1;
	}
	else if(arg=="-j"){
			object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/j"))
			return notify_fail("���Ѿ��ɹ�ͻ������������Բ����\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");	
		if (! where->query("sleep_room"))
			return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");	
		if (me->query("potential") - me->query("learned_points") < 20000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 150)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");				
		if (!me->query("jingjie/i"))
			return notify_fail("�㾳��δ�������������ڣ�����Ⱦָ��������Բ����������\n");
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("gain/2ap",5);
			me->add("gain/2dp",5);
			me->add("gain/break",5);
			me->add("gain/armor",5);
			me->set("jingjie/j",1);
			me->add("potential",-20000);
			me->add("yuanbao",-150);
			me->set("wudao","��������Բ��");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ����������Բ��������˱���,����,����,�Ƽ��������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());			
	return 1;

	}
	else if(arg=="-k"){
		object where;
		where = environment(me);		
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/k"))
			return notify_fail("���Ѿ��ɹ�ͻ���˽𵤾������š�\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");
		if ((int)me->query("potential") - me->query("learned_points") < 30000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 200)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");	
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");
		if (!me->query("jingjie/j"))
			return notify_fail("�㾳��δ����������Բ��������Ⱦָ�𵤾������ţ�����\n");
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("gain/2ap",5);
			me->add("gain/2dp",5);
			me->add("gain/break",5);
			me->add("gain/armor",5);
			me->add("potential",-30000);
			me->add("yuanbao",-200);
			me->set("jingjie/k",1);
			me->set("wudao","�𵤾�������");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�ƽ𵤾������ţ�����˱���,����,����,�Ƽ��������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());			
	return 1;
	}
	else if(arg=="-l"){
			object where;
			where = environment(me);
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/l"))
			return notify_fail("���Ѿ��ɹ�ͻ���˽𵤾������ڡ�\n");	
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");
		if (me->query("potential") - me->query("learned_points") < 30000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 200)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");	
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");
		if (!me->query("jingjie/k"))
			return notify_fail("�㾳��δ���𵤾������ţ�����Ⱦָ�𵤾������ڣ�����\n");
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("gain/2ap",5);
			me->add("gain/2dp",5);
			me->add("gain/break",5);
			me->add("gain/armor",5);
			me->set("jingjie/l",1);
			me->add("potential",-30000);
			me->add("yuanbao",-200);
			me->set("wudao","�𵤾�������");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�ƽ𵤾������ڣ�����˱���,����,����,�Ƽ��������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());
			
	return 1;
	}
	else if(arg=="-m"){
				object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/m"))
			return notify_fail("���Ѿ��ɹ�ͻ���˽𵤾������ڡ�\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");	
		if (me->query("potential") - me->query("learned_points") < 30000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 200)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");
		if (!me->query("jingjie/l"))
			return notify_fail("�㾳��δ���𵤾������ڣ�����Ⱦָ�𵤾������ڣ�������\n");	
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("gain/2ap",5);
			me->add("gain/2dp",5);
			me->add("gain/break",5);
			me->add("gain/armor",5);
			me->set("jingjie/m",1);
			me->add("potential",-30000);
			me->add("yuanbao",-200);
			me->set("wudao","�𵤾�������");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�ƽ𵤾������ڣ�����˱���,����,����,�Ƽ��������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());			
	return 1;
	}
	else if(arg=="-n"){
			object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/n"))
			return notify_fail("���Ѿ��ɹ�ͻ���˽𵤾������ڡ�\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");	
		if (! where->query("sleep_room"))
			return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");	
		if (me->query("potential") - me->query("learned_points") < 30000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 200)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");		
		if (!me->query("jingjie/m"))
			return notify_fail("�㾳��δ���𵤾������ڣ�����Ⱦָ�𵤾������ڣ�������\n");			
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("gain/2ap",5);
			me->add("gain/2dp",5);
			me->add("gain/break",5);
			me->add("gain/armor",5);
			me->set("jingjie/n",1);
			me->add("potential",-30000);
			me->add("yuanbao",-200);
			me->set("wudao","�𵤾�������");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�ƽ𵤾������ڣ�����˱���,����,����,�Ƽ��������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());			
	return 1;
	}
	else if(arg=="-o"){
			object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/o"))
			return notify_fail("���Ѿ��ɹ�ͻ���˽𵤾���Բ����\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");	
		if (! where->query("sleep_room"))
			return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");	
		if (me->query("potential") - me->query("learned_points") < 30000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 200)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");				
		if (!me->query("jingjie/n"))
			return notify_fail("�㾳��δ���𵤾������ڣ�����Ⱦָ�𵤾���Բ����������\n");
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("gain/2ap",5);
			me->add("gain/2dp",5);
			me->add("gain/break",5);
			me->add("gain/armor",5);
			me->set("jingjie/o",1);
			me->add("potential",-30000);
			me->add("yuanbao",-200);
			me->set("wudao","�𵤾���Բ��");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�ƽ𵤾���Բ��������˱���,����,����,�Ƽ��������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());			
	return 1;

	}
	else if(arg=="-p"){
		object where;
		where = environment(me);		
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/p"))
			return notify_fail("���Ѿ��ɹ�ͻ����ԪӤ�������š�\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");
		if (! where->query("sleep_room"))
			return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");
		if ((int)me->query("potential") - me->query("learned_points") < 40000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 250)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");	
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");
		if (!me->query("jingjie/o"))
			return notify_fail("�㾳��δ���𵤾���Բ��������ȾָԪӤ�������ţ�������\n");
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("gain/2ap",3);
			me->add("gain/2dp",3);
			me->add("gain/break",3);
			me->add("gain/armor",3);
			me->add("potential",-40000);
			me->add("yuanbao",-250);
			me->set("jingjie/p",1);
			me->set("wudao","ԪӤ��������");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ��ԪӤ�������ţ�����˱���,����,����,�Ƽ��������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());			
	return 1;
	}
	else if(arg=="-q"){
			object where;
			where = environment(me);
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/q"))
			return notify_fail("���Ѿ��ɹ�ͻ����ԪӤ�������ڡ�\n");	
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");
		if (! where->query("sleep_room"))
			return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");
		if (me->query("potential") - me->query("learned_points") < 40000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 250)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");	
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");
		if (!me->query("jingjie/p"))
			return notify_fail("�㾳��δ��ԪӤ�������ţ�����ȾָԪӤ�������ڣ�����\n");
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("gain/2ap",3);
			me->add("gain/2dp",3);
			me->add("gain/break",3);
			me->add("gain/armor",3);
			me->set("jingjie/q",1);
			me->add("potential",-40000);
			me->add("yuanbao",-250);
			me->set("wudao","ԪӤ��������");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ��ԪӤ�������ڣ�����˱���,����,����,�Ƽ��������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());
			
	return 1;
	}
	else if(arg=="-r"){
				object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/r"))
			return notify_fail("���Ѿ��ɹ�ͻ����ԪӤ�������ڡ�\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");
		if (! where->query("sleep_room"))
			return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");	
		if (me->query("potential") - me->query("learned_points") < 40000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 250)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");
		if (!me->query("jingjie/q"))
			return notify_fail("�㾳��δ��ԪӤ�������ڣ�����ȾָԪӤ�������ڣ�������\n");	
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("gain/2ap",3);
			me->add("gain/2dp",3);
			me->add("gain/break",3);
			me->add("gain/armor",3);
			me->set("jingjie/r",1);
			me->add("potential",-40000);
			me->add("yuanbao",-250);
			me->set("wudao","ԪӤ��������");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ��ԪӤ�������ڣ�����˱���,����,����,�Ƽ��������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());			
	return 1;
	}
	else if(arg=="-s"){
			object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/s"))
			return notify_fail("���Ѿ��ɹ�ͻ����ԪӤ�������ڡ�\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");	
		if (! where->query("sleep_room"))
			return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");	
		if (me->query("potential") - me->query("learned_points") < 40000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 250)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");		
		if (!me->query("jingjie/r"))
			return notify_fail("�㾳��δ��ԪӤ�������ڣ�����ȾָԪӤ�������ڣ�������\n");			
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("gain/2ap",3);
			me->add("gain/2dp",3);
			me->add("gain/break",3);
			me->add("gain/armor",3);
			me->set("jingjie/s",1);
			me->add("potential",-40000);
			me->add("yuanbao",-250);
			me->set("wudao","ԪӤ��������");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ��ԪӤ�������ڣ�����˱���,����,����,�Ƽ��������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());			
	return 1;
	}
	else if(arg=="-t"){
			object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/t"))
			return notify_fail("���Ѿ��ɹ�ͻ����ԪӤ����Բ����\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");	
		if (! where->query("sleep_room"))
			return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");	
		if (me->query("potential") - me->query("learned_points") < 40000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 250)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");				
		if (!me->query("jingjie/s"))
			return notify_fail("�㾳��δ��ԪӤ�������ڣ�����ȾָԪӤ����Բ����������\n");
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("gain/2ap",3);
			me->add("gain/2dp",3);
			me->add("gain/break",3);
			me->add("gain/armor",3);
			me->set("jingjie/t",1);
			me->add("potential",-40000);
			me->add("yuanbao",-250);
			me->set("wudao","ԪӤ����Բ��");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ��ԪӤ����Բ��������˱���,����,����,�Ƽ��������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());			
	return 1;
	}
	else if(arg=="-u"){
		object where;
		where = environment(me);		
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/u"))
			return notify_fail("���Ѿ��ɹ�ͻ���˳��Ͼ������š�\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");
		if (! where->query("sleep_room"))
			return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");
		if ((int)me->query("potential") - me->query("learned_points") < 50000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 300)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");	
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");
		if (!me->query("jingjie/t"))
			return notify_fail("�㾳��δ��ԪӤ����Բ��������Ⱦָ���Ͼ������ţ�����\n");
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("gain/2ap",3);
			me->add("gain/2dp",3);
			me->add("gain/break",3);
			me->add("gain/armor",3);
			me->add("potential",-50000);
			me->add("yuanbao",-300);
			me->set("jingjie/u",1);
			me->set("wudao","���Ͼ�������");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�Ƴ��Ͼ������ţ�����˱���,����,����,�Ƽ��������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());			
	return 1;
	}
	else if(arg=="-v"){
			object where;
			where = environment(me);
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/v"))
			return notify_fail("���Ѿ��ɹ�ͻ���˳��Ͼ������ڡ�\n");	
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");
		if (! where->query("sleep_room"))
			return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");
		if (me->query("potential") - me->query("learned_points") < 50000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 300)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");	
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");
		if (!me->query("jingjie/u"))
			return notify_fail("�㾳��δ�����Ͼ������ţ�����Ⱦָ���Ͼ������ڣ�����\n");
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("gain/2ap",3);
			me->add("gain/2dp",3);
			me->add("gain/break",3);
			me->add("gain/armor",3);
			me->set("jingjie/v",1);
			me->add("potential",-50000);
			me->add("yuanbao",-300);
			me->set("wudao","���Ͼ�������");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�Ƴ��Ͼ������ڣ�����˱���,����,����,�Ƽ��������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());
			
	return 1;
	}
	else if(arg=="-w"){
				object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/w"))
			return notify_fail("���Ѿ��ɹ�ͻ���˳��Ͼ������ڡ�\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");
		if (! where->query("sleep_room"))
			return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");	
		if (me->query("potential") - me->query("learned_points") < 50000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 300)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");
		if (!me->query("jingjie/v"))
			return notify_fail("�㾳��δ�����Ͼ������ڣ�����Ⱦָ���Ͼ������ڣ�������\n");	
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("gain/2ap",3);
			me->add("gain/2dp",3);
			me->add("gain/break",3);
			me->add("gain/armor",3);
			me->set("jingjie/w",1);
			me->add("potential",-50000);
			me->add("yuanbao",-300);
			me->set("wudao","���Ͼ�������");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�Ƴ��Ͼ������ڣ�����˱���,����,����,�Ƽ��������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());			
	return 1;
	}
	else if(arg=="-x"){
			object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/x"))
			return notify_fail("���Ѿ��ɹ�ͻ���˳��Ͼ������ڡ�\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");	
		if (! where->query("sleep_room"))
			return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");	
		if (me->query("potential") - me->query("learned_points") < 50000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 300)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");		
		if (!me->query("jingjie/w"))
			return notify_fail("�㾳��δ�����Ͼ������ڣ�����Ⱦָ���Ͼ������ڣ�������\n");			
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("gain/2ap",3);
			me->add("gain/2dp",3);
			me->add("gain/break",3);
			me->add("gain/armor",3);
			me->set("jingjie/x",1);
			me->add("potential",-50000);
			me->add("yuanbao",-300);
			me->set("wudao","���Ͼ�������");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�Ƴ��Ͼ������ڣ�����˱���,����,����,�Ƽ��������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());			
	return 1;
	}
	else if(arg=="-y"){
			object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/y"))
			return notify_fail("���Ѿ��ɹ�ͻ���˳��Ͼ���Բ����\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");	
		if (! where->query("sleep_room"))
			return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");	
		if (me->query("potential") - me->query("learned_points") < 50000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 300)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");				
		if (!me->query("jingjie/x"))
			return notify_fail("�㾳��δ�����Ͼ������ڣ�����Ⱦָ���Ͼ���Բ����������\n");
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("gain/2ap",3);
			me->add("gain/2dp",3);
			me->add("gain/break",3);
			me->add("gain/armor",3);
			me->set("jingjie/y",1);
			me->add("potential",-50000);
			me->add("yuanbao",-300);
			me->set("wudao","���Ͼ���Բ��");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�Ƴ��Ͼ���Բ��������˱���,����,����,�Ƽ��������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());			
	return 1;

	}
	else if(arg=="-z"){
		object where;
		where = environment(me);		
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/z"))
			return notify_fail("���Ѿ��ɹ�ͻ���˷��񾳡����š�\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");
		if ((int)me->query("potential") - me->query("learned_points") < 60000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 350)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");	
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");
		if (!me->query("jingjie/y"))
			return notify_fail("�㾳��δ�����Ͼ���Բ��������Ⱦָ���񾳡����ţ�����\n");
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("gain/2ap",3);
			me->add("gain/2dp",3);
			me->add("gain/break",3);
			me->add("gain/armor",3);
			me->add("potential",-60000);
			me->add("yuanbao",-350);
			me->set("jingjie/z",1);
			me->set("wudao","���񾳡�����");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�Ʒ��񾳡����ţ�����˱���,����,����,�Ƽ��������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());			
	return 1;
	}
	else if(arg=="-1"){
			object where;
			where = environment(me);
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/1"))
			return notify_fail("���Ѿ��ɹ�ͻ���˷��񾳡����ڡ�\n");	
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");
		if (me->query("potential") - me->query("learned_points") < 60000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 350)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");	
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");
		if (!me->query("jingjie/z"))
			return notify_fail("�㾳��δ�����񾳡����ţ�����Ⱦָ���񾳡����ڣ�����\n");
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("gain/2ap",3);
			me->add("gain/2dp",3);
			me->add("gain/break",3);
			me->add("gain/armor",3);
			me->set("jingjie/1",1);
			me->add("potential",-60000);
			me->add("yuanbao",-350);
			me->set("wudao","���񾳡�����");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�Ʒ��񾳡����ڣ�����˱���,����,����,�Ƽ��������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());
			
	return 1;
	}
	else if(arg=="-2"){
				object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/2"))
			return notify_fail("���Ѿ��ɹ�ͻ���˷��񾳡����ڡ�\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");	
		if (me->query("potential") - me->query("learned_points") < 60000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 350)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");
		if (!me->query("jingjie/1"))
			return notify_fail("�㾳��δ�����񾳡����ڣ�����Ⱦָ���񾳡����ڣ�������\n");	
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("gain/2ap",3);
			me->add("gain/2dp",3);
			me->add("gain/break",3);
			me->add("gain/armor",3);
			me->set("jingjie/2",1);
			me->add("potential",-60000);
			me->add("yuanbao",-350);
			me->set("wudao","���񾳡�����");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�Ʒ��񾳡����ڣ�����˱���,����,����,�Ƽ��������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());			
	return 1;
	}
	else if(arg=="-3"){
			object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/3"))
			return notify_fail("���Ѿ��ɹ�ͻ���˷��񾳡����ڡ�\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");	
		if (! where->query("sleep_room"))
			return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");	
		if (me->query("potential") - me->query("learned_points") < 60000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 350)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");		
		if (!me->query("jingjie/2"))
			return notify_fail("�㾳��δ�����񾳡����ڣ�����Ⱦָ���񾳡����ڣ�������\n");			
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("gain/2ap",3);
			me->add("gain/2dp",3);
			me->add("gain/break",3);
			me->add("gain/armor",3);
			me->set("jingjie/3",1);
			me->add("potential",-60000);
			me->add("yuanbao",-350);
			me->set("wudao","���񾳡�����");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�Ʒ��񾳡����ڣ�����˱���,����,����,�Ƽ��������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());			
	return 1;
	}
	else if(arg=="-4"){
			object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/4"))
			return notify_fail("���Ѿ��ɹ�ͻ���˷��񾳡�Բ����\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");	
		if (! where->query("sleep_room"))
			return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");	
		if (me->query("potential") - me->query("learned_points") < 60000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 350)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");				
		if (!me->query("jingjie/3"))
			return notify_fail("�㾳��δ�����񾳡����ڣ�����Ⱦָ���񾳡�Բ����������\n");
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("gain/2ap",3);
			me->add("gain/2dp",3);
			me->add("gain/break",3);
			me->add("gain/armor",3);
			me->set("jingjie/4",1);
			me->add("potential",-60000);
			me->add("yuanbao",-350);
			me->set("wudao","���񾳡�Բ��");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�Ʒ��񾳡�Բ��������˱���,����,����,�Ƽ��������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());			
	return 1;
	}
	else if(arg=="-5"){
		object where;
		where = environment(me);		
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/5"))
			return notify_fail("���Ѿ��ɹ�ͻ���˺��徳�����š�\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");
		if (! where->query("sleep_room"))
			return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");
		if ((int)me->query("potential") - me->query("learned_points") < 40000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 400)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");	
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");
		if (!me->query("jingjie/4"))
			return notify_fail("�㾳��δ�����񾳡����ţ�����Ⱦָ���徳�����ڣ�����\n");
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("xuruo_perform",5);
			me->add("no_perform",5);
			me->add("reduce_damage",5);
			me->add("reduce_busy",5);
			me->add("potential",-10000);
			me->add("yuanbao",-400);
			me->set("jingjie/5",1);
			me->set("wudao","���徳������");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�ƺ��徳�����ţ��������������,��Ĭ����,�����˺�,����æ���������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());			
	return 1;
	}
	else if(arg=="-6"){
			object where;
			where = environment(me);
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/6"))
			return notify_fail("���Ѿ��ɹ�ͻ���˺��徳�����ڡ�\n");	
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");
		if (! where->query("sleep_room"))
			return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");
		if (me->query("potential") - me->query("learned_points") < 40000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 400)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");	
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");
		if (!me->query("jingjie/5"))
			return notify_fail("�㾳��δ�����徳�����ţ�����Ⱦָ���徳�����ڣ�����\n");
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("xuruo_perform",5);
			me->add("no_perform",5);
			me->add("reduce_damage",5);
			me->add("reduce_busy",5);
			me->set("jingjie/6",1);
			me->add("potential",-10000);
			me->add("yuanbao",-400);
			me->set("wudao","���徳������");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�ƺ��徳�����ڣ��������������,��Ĭ����,�����˺�,����æ���������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());
			
	return 1;
	}
	else if(arg=="-7"){
				object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/7"))
			return notify_fail("���Ѿ��ɹ�ͻ���˺��徳�����ڡ�\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");
		if (! where->query("sleep_room"))
			return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");	
		if (me->query("potential") - me->query("learned_points") < 40000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 400)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");
		if (!me->query("jingjie/6"))
			return notify_fail("�㾳��δ�����徳�����ڣ�����Ⱦָ���徳�����ڣ�������\n");	
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("xuruo_perform",5);
			me->add("no_perform",5);
			me->add("reduce_damage",5);
			me->add("reduce_busy",5);
			me->set("jingjie/7",1);
			me->add("potential",-10000);
			me->add("yuanbao",-400);
			me->set("wudao","���徳������");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�ƺ��徳�����ڣ��������������,��Ĭ����,�����˺�,����æ���������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());			
	return 1;
	}
	else if(arg=="-8"){
			object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/8"))
			return notify_fail("���Ѿ��ɹ�ͻ���˺��徳�����ڡ�\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");	
		if (! where->query("sleep_room"))
			return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");	
		if (me->query("potential") - me->query("learned_points") < 40000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 400)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");		
		if (!me->query("jingjie/7"))
			return notify_fail("�㾳��δ�����徳�����ڣ�����Ⱦָ���徳�����ڣ�������\n");			
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("xuruo_perform",5);
			me->add("no_perform",5);
			me->add("reduce_damage",5);
			me->add("reduce_busy",5);
			me->set("jingjie/8",1);
			me->add("potential",-10000);
			me->add("yuanbao",-400);
			me->set("wudao","���徳������");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�ƺ��徳�����ڣ��������������,��Ĭ����,�����˺�,����æ���������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());			
	return 1;
	}
	else if(arg=="-9"){
			object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/9"))
			return notify_fail("���Ѿ��ɹ�ͻ���˺��徳��Բ����\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");	
		if (! where->query("sleep_room"))
			return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");	
		if (me->query("potential") - me->query("learned_points") < 40000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 400)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");				
		if (!me->query("jingjie/8"))
			return notify_fail("�㾳��δ�����徳�����ڣ�����Ⱦָ���徳��Բ����������\n");
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("xuruo_perform",5);
			me->add("no_perform",5);
			me->add("reduce_damage",5);
			me->add("reduce_busy",5);
			me->set("jingjie/9",1);
			me->add("potential",-10000);
			me->add("yuanbao",-400);
			me->set("wudao","���徳��Բ��");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�ƺ��徳��Բ�����������������,��Ĭ����,�����˺�,����æ���������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());			
	return 1;
	}
	else if(arg=="-10"){
		object where;
		where = environment(me);		
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/10"))
			return notify_fail("���Ѿ��ɹ�ͻ���˴�˾������š�\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");
		if (! where->query("sleep_room"))
			return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");
		if ((int)me->query("potential") - me->query("learned_points") < 50000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 150)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");	
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");
		if (!me->query("jingjie/9"))
			return notify_fail("�㾳��δ�����徳��Բ��������Ⱦָ��˾������ţ�����\n");
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("xuruo_perform",5);
			me->add("no_perform",5);
			me->add("reduce_damage",5);
			me->add("reduce_busy",5);
			me->add("potential",-20000);
			me->add("yuanbao",-450);
			me->set("jingjie/10",1);
			me->set("wudao","��˾�������");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�ƴ�˾������ţ��������������,��Ĭ����,�����˺�,����æ���������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());			
	return 1;
	}
	else if(arg=="-11"){
			object where;
			where = environment(me);
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/11"))
			return notify_fail("���Ѿ��ɹ�ͻ���˴�˾������ڡ�\n");	
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");
		if (! where->query("sleep_room"))
			return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");
		if (me->query("potential") - me->query("learned_points") < 50000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 150)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");	
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");
		if (!me->query("jingjie/10"))
			return notify_fail("�㾳��δ����˾������ţ�����Ⱦָ��˾������ڣ�����\n");
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("xuruo_perform",5);
			me->add("no_perform",5);
			me->add("reduce_damage",5);
			me->add("reduce_busy",5);
			me->set("jingjie/11",1);
			me->add("potential",-20000);
			me->add("yuanbao",-450);
			me->set("wudao","��˾�������");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�ƴ�˾������ڣ��������������,��Ĭ����,�����˺�,����æ���������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());
			
	return 1;
	}
	else if(arg=="-12"){
				object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/12"))
			return notify_fail("���Ѿ��ɹ�ͻ���˴�˾������ڡ�\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");
		if (! where->query("sleep_room"))
			return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");	
		if (me->query("potential") - me->query("learned_points") < 50000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 150)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");
		if (!me->query("jingjie/11"))
			return notify_fail("�㾳��δ����˾������ڣ�����Ⱦָ��˾������ڣ�������\n");	
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("xuruo_perform",5);
			me->add("no_perform",5);
			me->add("reduce_damage",5);
			me->add("reduce_busy",5);
			me->set("jingjie/12",1);
			me->add("potential",-20000);
			me->add("yuanbao",-450);
			me->set("wudao","��˾�������");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�ƴ�˾������ڣ��������������,��Ĭ����,�����˺�,����æ���������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());			
	return 1;
	}
	else if(arg=="-13"){
			object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/13"))
			return notify_fail("���Ѿ��ɹ�ͻ���˴�˾������ڡ�\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");	
		if (! where->query("sleep_room"))
			return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");	
		if (me->query("potential") - me->query("learned_points") < 50000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 150)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");		
		if (!me->query("jingjie/12"))
			return notify_fail("�㾳��δ����˾������ڣ�����Ⱦָ��˾������ڣ�������\n");			
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("xuruo_perform",5);
			me->add("no_perform",5);
			me->add("reduce_damage",5);
			me->add("reduce_busy",5);
			me->set("jingjie/13",1);
			me->add("potential",-20000);
			me->add("yuanbao",-450);
			me->set("wudao","��˾�������");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�ƴ�˾������ڣ��������������,��Ĭ����,�����˺�,����æ���������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());			
	return 1;
	}
	else if(arg=="-14"){
			object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/14"))
			return notify_fail("���Ѿ��ɹ�ͻ���˴�˾���Բ����\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");	
		if (! where->query("sleep_room"))
			return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");	
		if (me->query("potential") - me->query("learned_points") < 50000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 150)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");				
		if (!me->query("jingjie/13"))
			return notify_fail("�㾳��δ����˾������ڣ�����Ⱦָ��˾���Բ����������\n");
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("xuruo_perform",5);
			me->add("no_perform",5);
			me->add("reduce_damage",5);
			me->add("reduce_busy",5);
			me->set("jingjie/14",1);
			me->add("potential",-20000);
			me->add("yuanbao",-450);
			me->set("wudao","��˾���Բ��");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�ƴ�˾���Բ�����������������,��Ĭ����,�����˺�,����æ���������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());			
	return 1;

	}
	else if(arg=="-15"){
		object where;
		where = environment(me);		
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/15"))
			return notify_fail("���Ѿ��ɹ�ͻ���˶ɽپ������š�\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");
		if ((int)me->query("potential") - me->query("learned_points") < 60000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 500)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");	
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");
		if (!me->query("jingjie/14"))
			return notify_fail("�㾳��δ����˾���Բ��������Ⱦָ�ɽپ������ţ�����\n");
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("xuruo_perform",5);
			me->add("no_perform",5);
			me->add("reduce_damage",5);
			me->add("reduce_busy",5);
			me->add("potential",-30000);
			me->add("yuanbao",-500);
			me->set("jingjie/15",1);
			me->set("wudao","�ɽپ�������");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�ƶɽپ������ţ��������������,��Ĭ����,�����˺�,����æ���������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());			
	return 1;
	}
	else if(arg=="-16"){
			object where;
			where = environment(me);
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/16"))
			return notify_fail("���Ѿ��ɹ�ͻ���˶ɽپ������ڡ�\n");	
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");
		if (me->query("potential") - me->query("learned_points") < 60000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 500)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");	
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");
		if (!me->query("jingjie/15"))
			return notify_fail("�㾳��δ���ɽپ������ţ�����Ⱦָ�ɽپ������ڣ�����\n");
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("xuruo_perform",5);
			me->add("no_perform",5);
			me->add("reduce_damage",5);
			me->add("reduce_busy",5);
			me->set("jingjie/16",1);
			me->add("potential",-30000);
			me->add("yuanbao",-500);
			me->set("wudao","�ɽپ�������");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�ƶɽپ������ڣ��������������,��Ĭ����,�����˺�,����æ���������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());
			
	return 1;
	}
	else if(arg=="-17"){
				object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/17"))
			return notify_fail("���Ѿ��ɹ�ͻ���˶ɽپ������ڡ�\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");	
		if (me->query("potential") - me->query("learned_points") < 60000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 500)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");
		if (!me->query("jingjie/16"))
			return notify_fail("�㾳��δ���ɽپ������ڣ�����Ⱦָ�ɽپ������ڣ�������\n");	
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("xuruo_perform",5);
			me->add("no_perform",5);
			me->add("reduce_damage",5);
			me->add("reduce_busy",5);
			me->set("jingjie/17",1);
			me->add("potential",-30000);
			me->add("yuanbao",-500);
			me->set("wudao","�ɽپ�������");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�ƶɽپ������ڣ��������������,��Ĭ����,�����˺�,����æ���������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());			
	return 1;
	}
	else if(arg=="-18"){
			object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/18"))
			return notify_fail("���Ѿ��ɹ�ͻ���˶ɽپ������ڡ�\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");	
		if (! where->query("sleep_room"))
			return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");	
		if (me->query("potential") - me->query("learned_points") < 60000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 500)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");		
		if (!me->query("jingjie/17"))
			return notify_fail("�㾳��δ���ɽپ������ڣ�����Ⱦָ�ɽپ������ڣ�������\n");			
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("xuruo_perform",5);
			me->add("no_perform",5);
			me->add("reduce_damage",5);
			me->add("reduce_busy",5);
			me->set("jingjie/18",1);
			me->add("potential",-30000);
			me->add("yuanbao",-500);
			me->set("wudao","�ɽپ�������");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�ƶɽپ������ڣ��������������,��Ĭ����,�����˺�,����æ���������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());			
	return 1;
	}
	else if(arg=="-19"){
			object where;
		seteuid(getuid());
		where = environment(me);	
		if (where->query("pigging"))
			return notify_fail("��Ŀǰ������ͻ��������\n");
		if (me->query("jingjie/19"))
			return notify_fail("���Ѿ��ɹ�ͻ���˶ɽپ���Բ����\n");
		if (! where->query("no_fight") && ! where->query("owner_special"))
			return notify_fail("����������������զ�죿\n");	
		if (! where->query("sleep_room"))
			return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");	
		if (me->query("potential") - me->query("learned_points") < 60000)
			return notify_fail("���Ǳ�ܲ������޷������ɵ����硣\n");
		if ((int)me->query("yuanbao") - me->query("learned_points") < 500)
			return notify_fail("�����ʯ�������޷������ɵ����硣\n");
		if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
			return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
			return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");
		if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
			return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");				
		if (!me->query("jingjie/18"))
			return notify_fail("�㾳��δ���ɽپ������ڣ�����Ⱦָ�ɽپ���Բ����������\n");
			message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
			me->add("xuruo_perform",5);
			me->add("no_perform",5);
			me->add("reduce_damage",5);
			me->add("reduce_busy",5);
			me->set("jingjie/19",1);
			me->add("potential",-30000);
			me->add("yuanbao",-500);
			me->set("wudao","�ɽپ���Բ��");
			message("channel:chat",HBWHT"���"HIY"��"+me->query("name")+"����ǧ����࣬����ͻ�ƶɽپ���Բ�����������������,��Ĭ����,�����˺�,����æ���������Ը�+5��Ľ����������ǿ�ϲ�ɺأ���\n"NOR,users());			
	return 1;
	}
	else if(arg=="-suoxiang"){
			object where;

	return 1;	
	}
	else if(arg=="-guanjue"){
		    
	return 1;	
	}
	return 1;
}

int help(object me)
{
     write(@HELP
ָ���ʽ: uplv [-s]

���ָ������������Ϊ�����ȼ���

HELP
    );
    return 1;
}
