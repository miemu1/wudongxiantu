//ɨ������ת������
int main(object me, string arg)
{   object ob;
     int exp=60000;
     int pot=80000;
     int mar=10000;
  /*    int zhuanshi=me->query("zhuanshi");
    exp+=exp*(zhuanshi*5)/10;
    pot+=pot*(zhuanshi*5)/10;
    mar+=mar*(zhuanshi*5)/10;
    write(exp+"\n"); */
     if(me->query("shimen/today")<1000) return notify_fail("���ʦ�Ŵ�������1000�������ܽ���ɨ��\n");
     
   /*  if(! objectp(ob = present(arg, environment(me))))
			return notify_fail("����û������ˣ�����ôɨ��ʦ�ţ�\n"); */
	if(me->query("shimen/today")>=20000) return notify_fail("���ʦ�Ŵ����Ѿ�����\n");
	if(!arg) {
	tell_object(me,"��Ҫ������ɨ������\n");
	tell_object(me,HIR"�߼�ɨ��: "NOR"100��ʯɨ��100��ʦ�Ż��100%������"ZJURL("cmds:sao -gao")ZJSIZE(20)"�߼�ɨ��"NOR+"\n");
	tell_object(me,HIM"�м�ɨ��: "NOR"100��ʯƱɨ��100��ʦ�Ż��70%������"ZJURL("cmds:sao -zhong")ZJSIZE(20)"�м�ɨ��"NOR+"\n");
	tell_object(me,HIW"�ͼ�ɨ��: "NOR"100�ƽ�ɨ��100��ʦ�Ż��50%������ "ZJURL("cmds:sao -di")ZJSIZE(20)"�ͼ�ɨ��"NOR+"\n");
	}
	if(arg=="-gao"){
    if(me->query("yuanbao")<100){
    return notify_fail("�����ʯ����100\n");
    }
	me->add("shimen/today",100);
	me->add("yuanbao",-100);
	me->add("combat_exp",exp);
	me->add("potential",pot);
	me->add("experience",mar);
	tell_object(me,HIC"�㻨��100��ʯɨ����100ʦ�Ż����\n");
	tell_object(me,HIG+exp+"��Ϊ\n");
	tell_object(me,HIG+pot+"Ǳ��\n");
	tell_object(me,HIG+mar+"ʵս���\n");
	tell_object(me,ZJURL("cmds:sao -gao")ZJSIZE(20)"�����߼�ɨ��"NOR+"\n");

	}
	if(arg=="-zhong"){
	if(me->query("yuanbao_2")<100){
    return notify_fail("�����ʯƱ����100\n");
    }
    //ֻ��70%������
    write(exp+"\n");
    exp=exp*7/10;
    pot=pot*7/10;
    mar=mar*7/10;
    write("exp:"+exp+"\n");
	me->add("shimen/today",100);
	me->add("yuanbao_2",-100);
	me->add("combat_exp",exp);
	me->add("potential",pot);
	me->add("experience",mar);
	tell_object(me,HIC"�㻨��100��ʯƱɨ����100ʦ�Ż����\n");
	tell_object(me,HIG+exp+"��Ϊ\n");
	tell_object(me,HIG+pot+"Ǳ��\n");
	tell_object(me,HIG+mar+"ʵս���\n");
	tell_object(me,ZJURL("cmds:sao -zhong")ZJSIZE(20)"�����м�ɨ��"NOR+"\n");
	}
	if(arg=="-di"){
	if(me->query("balance")<1000000){
    return notify_fail("��Ǯׯ��Ǯ����100�ƽ�\n");
    }
    write(exp+"\n");
    exp=exp*5/10;
    pot=pot*5/10;
    mar=mar*5/10;
    write("exp:"+exp+"\n");
	me->add("shimen/today",100);
	me->add("balance",-1000000);
	me->add("combat_exp",exp);
	me->add("potential",pot);
	me->add("experience",mar);
	tell_object(me,HIC"�㻨��100�ƽ�ɨ����100ʦ�Ż����\n");
	tell_object(me,HIG+exp+"��Ϊ\n");
	tell_object(me,HIG+pot+"Ǳ��\n");
	tell_object(me,HIG+mar+"ʵս���\n");
	tell_object(me,ZJURL("cmds:sao -di")ZJSIZE(20)"�����ͼ�ɨ��"NOR+"\n");
	 }
	   /**   
	   if(me->query("shimen/today")>1000){
	  me->add("shimen/today",100);
	  if(me->query("shimen/today")>=4000) me->set("shimen/today",4000);
	  
	  me->add("combet_exp",3000);
	  me->add("potential",4000);
	  me->add("gongxian",25);
	  tell_object(me,CYN+ob->name()+"�����㣬�㻨����100��ʦ�Ŵ���ɨ���������3000��Ϊ4000Ǳ��25��ʦ�Ź���\n"NOR);
	  return 1;
	 }else{
	 tell_object(me,CYN+ob->name()+"������: ���ʦ�Ŵ�������1000�޷�����ɨ��\n"NOR);
	 return 1;
	 }/**/
	 }