//gui制作

#include <ansi.h>
#include <command.h>
inherit NPC;
void play_sound_0(object speaker,int index);
void play_sound_1(object speaker,int index);
void play_sound_2(object speaker,int index);
void play_sound_3(object speaker,int index);
void play_sound_4(object speaker,int index);
void create()
{
        set_name(HIR"貂蝉"NOR, ({ "diao chan","diao","chan",}));
        set("title", HIY "四大美女之闭月" NOR);
        set("gender", "女性");
        set("age", 22);
        set("long", @LONG
她一袭粉衣，模样端庄之中透露着一股说不出来的妖媚之感，
青丝披落，仅仅用一条粉色的发带系着，粉色的色彩衬的女子
肌肤透着一股淡淡的粉色，煞是美丽，凤眸潋滟，可夺魂摄魄，
荡人心神，唇若点樱，引人无限遐想。
LONG);
        set("attitude", "friendly");
        set("str", 800);
        set("int", 800);
        set("con", 800);
        set("dex", 800);
        set("per", 800);
        set("shen_type", 1);
        set("qi", 500000000);
        set("max_qi", 500000000);
        set("jing", 200000000);
     
        set("jingli", 200000000);
        set("max_jingli", 200000000);
        set("neili", 300000000);
        set("max_neili", 300000000);
        set("jiali", 100000);
        set("combat_exp", 80000000000);
        set("level", 50);
     /*   set_skill("koujiao-jiqiao", 2000);        //口交技巧
        set_skill("xingjiao-jiqiao", 2000);      //性交技巧
        set_skill("gangjiao-jiqiao", 2000);
        set_skill("rujiao-jiqiao", 2000);
        set_skill("dafeiji", 2000);
        set_skill("shouyin-jiqiao", 2000);
        set_skill("ziwei-jiqiao", 2000);
        set_skill("zujiao-jiqiao", 2000);
        set_skill("qicheng-jiqiao", 2000);
        set_skill("aifu", 2000);
        set_skill("zhongchu-jiqiao", 2000);
        set_skill("chaochui-jiqiao", 2000);
	  set_skill("parry", 100000);
        set_skill("unarmed", 100000);
        set_skill("force", 100000);
        set_skill("sword", 100000);
        set_skill("dodge", 100000);
        set_skill("fengye-xiangsi", 100000);
        set_skill("mingyu-gong", 100000);
        set_skill("love-sword", 100000);
        set_skill("zuoyou-hubo", 100000);
        set_skill("literate", 100000);
        set_skill("count", 100000);
        set_skill("qimen-xuanshu", 100000);
        set_skill("martial-cognize", 100000);
        map_skill("force", "mingyu-gong");
        map_skill("dodge", "fengye-xiangsi");
        map_skill("sword", "love-sword");
        map_skill("parry", "love-sword");
        map_skill("unarmed", "mingyu-gong");
        prepare_skill("unarmed", "mingyu-gong");*/


        set_temp("apply/attack", 80000);
        set_temp("apply/defense", 80000);
        set_temp("apply/damage", 80000);
        set_temp("apply/unarmed_damage", 80000);
        set_temp("apply/armor", 80000);


        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                //(: command("perform strike.wang and unarmed.you") :),
                //(: exert_function, "recover" :),
                //(: exert_function, "powerup" :),
                //(: perform_action, "whip.feng twice" :),
        }) );
        setup();
        carry_object("/clone/weapon/changbian")->wield();
        carry_object("/clone/cloth/baipao")->wear();
}
void init()
{
        add_action("do_koujiao","koujiao");
        add_action("do_rujiao", "rujiao");
        add_action("do_liujiu", "liujiu");
        add_action("do_zujiao", "zujiao");
	  add_action("do_ziwei",  "ziwei");
}
int do_koujiao(string arg)
{

        play_sound_0(this_object(),0);
        return 1;
}
int do_rujiao(string arg)
{

        play_sound_1(this_object(),0);
        return 1;
}
int do_liujiu(string arg)
{

        play_sound_2(this_object(),0);
        return 1;
}
int do_zujiao(string arg)
{

        play_sound_3(this_object(),0);
        return 1;
}
int do_ziwei(string arg)
{

        play_sound_4(this_object(),0);
        return 1;
}

void play_sound_0(object speaker,int index) 
{
        if(!environment())
                return;
        if(!speaker)
                return;
    //    if (environment(speaker)->query("short") != "温柔乡")
    //    {
     //        write(HIR "你扶着貂蝉的螓首向你的胯下按去，貂蝉面红耳赤的抓住你的手，吐气如兰：“好老公，这里真的不行，等咱们回温柔乡，合欢床上奴家一切依你好不好”。\n" NOR);
      //          return;
      //  }
      switch (index)  
	{
                case(0):
                        tell_room(environment(),HIG"貂蝉搂着你的脖子看着你，眼波流转，柔柔地说：
“主人，让奴家来服侍你好不好……”说完，她跪在你坐在床沿张开了的两腿中间，
双手握住朝天矗立着的粗粗的肉棒，仰起了脸张开嘴唇贴到你的肉棒下面股缝里，
把肉棒下的阴囊整个吞进了嘴里吮吸，用舌头舔着袋囊拨动里面的两个小蛋蛋。\n"NOR);
                        break;
                case(1):
                        tell_room(environment(),HIR"过了一会，她伸出了舌头快速抖动着，从垂着的袋囊舔起，慢慢沿着肉棒舔了上来，
一直舔到了上面红红的龟头上，然后低下头，从上往下一口把它吞进了嘴里。貂蝉开始上下摆动着头，
含着粗大的肉棒吞吐着，让它在她嘴里上下进出，一面伸出手摸向你股间悬着的袋囊把它托在手心里轻轻揉捏，
还有一只手在你身上滑动着抚摸你的股间和大腿、臀部。貂蝉一会儿把粗粗的肉棒含在嘴里一面吞吐着，
一面用舌头灵巧地上下游动着舔着，缠卷着大肉棒，从根部一直舔上来缠绕住龟头舔卷。\n"NOR);
                        break;
                case(2):
                        tell_room(environment(),HIM"一会儿从上面向下把肉棒吞进嘴里，含着肉棒，一面吮吸一面用舌头拨着头上的小裂缝。
过了一会，她又把它横过来，用两片嘴唇含住了横衔在嘴里，上下滑动着用舌头在嘴里舔卷它，
或是用手握住了肉棒的下半截上下拉动，把上半截含在嘴里吞吐。你看着貂蝉在你两腿间那不断的吞吐含弄，
一阵阵消魂快感，从被她在嘴里含弄着的肉棒上升起，那极度的快感几乎让人颤抖喊叫起来。\n"NOR);
                        break;
				case(3):
                        tell_room(environment(),HIW"你被貂蝉的小嘴弄得肉棒和小腹一阵接一阵地发紧，呼吸也急促起来，变成粗重的喘息。
貂蝉听见了你的喘息声，嘴里顿时发出了“唔~唔~~”的呻吟声，一下加快了嘴和唇舌的动作，
一面两只手握住肉棒的下半截揉动，抚摸着下面的阴囊，一面上下摆动着头，猛地用力吮吸着上半截的肉棒，
把它在嘴里快速吞进吐出，舌头也在嘴里抖动着上下缠绕、舔卷着粗涨滚热的大肉棒。
随着从她嘴里的肉棒上传来的极度快感和唇舌刺激，你嘴里和鼻子里粗重的喘息几乎变成了吼叫。\n"NOR);
                        break;
				case(4):
                        tell_room(environment(),HIY"你的肉棒顿时在她嘴里一下下快要不受控制地跳动着鼓涨起来，
小腹、臀部和会阴的肌肉开始一阵阵的抽搐抖动，使你忍不住把身体弓了起来，
向前俯下身去并拢了双腿，夹住了她的脸捧着，抬着臀部把被她小嘴和舌头在吮吸、吞吐和舔卷着的肉棒，
在一下一下的跳动和鼓涨中伸进她嘴里耸动起来。\n"NOR);
                        break;
				case(5):
                        tell_room(environment(),HIC"越来越粗重，越来越大的喘息声中，你的小腹、臀部和大腿的肌肉突然不自觉地抖动夹紧，
在她嘴里被吞吐和抽插的肉棒也猛一下失控，剧烈地涨粗、跳动和痉挛着，接着你重重地喘息着吼了一声，
一股热热的精液从肉棒头上猛地喷射了出去。貂蝉见状“啊……”地一阵呻吟，张开了嘴，
握住正在射精的肉棒，把舌头伸到肉棒下面快速抖动着舔着它，缠卷着喷射着精液的肉棒。\n"NOR);
                        break;
				case(6):
                        tell_room(environment(),HIG"你猛地站起身来，用双手抱着貂蝉的俏脸，把她的头紧紧按向你抽搐的两腿中间，
将正在射精的肉棒猛地塞进她嘴里抽插起来，粗大的肉棒从她嘴里抽出的时候，
可以看见那一条条白色粘稠的精液从龟头上笔直地射进她张开呻吟着的小嘴里，
射在她的抖动舔卷着肉棒的舌头上和口腔里，插入的时候，那一股股精液一下下直接射进了貂蝉的咽喉。\n"NOR);
                        break;
				case(7):
                        tell_room(environment(),HIM"你在身体一阵阵剧烈的抽搐和被她拨燎着的极度快乐中喘息吼叫着，
把射着精液的粗大肉棒一下下插入她嘴里猛烈地抽动，抽插中热热的精液一次又一次全部射入了貂蝉张着的小嘴里。
粗大的肉棒在她嘴里一阵的剧烈发射过后，你长长地呼出了一口气，松弛了下来，
射精后的肉棒还塞在貂蝉的嘴里，她的嘴里含满着你射出的精液。\n"NOR);
                        break;
				case(8):
                        tell_room(environment(),HIR"貂蝉呻吟着仰起脸看着你，张开了嘴，让你看着她嘴里含得满满的白色精液，
然后伸出舌头轻轻舔了几下还在跳动涨鼓着的肉棒，把它含进嘴里，缓缓地吞吐着用舌头上下舔卷，
一面慢慢地把嘴里的精液一口一口地咽了下去。你一把抱起貂蝉把她紧紧搂进怀里在她耳边说：
“乖婵儿，你真是个小骚货，小妖精……老公要一辈子操你。”然后搂着貂蝉和她一起躺进了被窝，
让她枕着你的手臂，怀着激情过后的安逸和满心的爱意一起沉沉睡去。\n"NOR);
                        break;
                default: 
                        //delete_temp("in_speech", speaker);
                        return;

        }
        call_out("play_sound_0",1,speaker,++index);
}
void play_sound_1(object speaker,int index) 
{
        if(!environment())
                return;
        if(!speaker)
                return;
        //if (environment(speaker)->query("short") != "温柔乡")
      //  {
       //      write(HIR "你隔着衣服揉捏着貂蝉的奶子，貂蝉面红耳赤的抓住你的手，吐气如兰：“好老公，这里真的不行，等咱们回温柔乡，合欢床上奴家一切依你好不好”。\n" NOR);
       //         return;
      //  }
      switch (index)  
	{
                case(0):
                        tell_room(environment(),HIG"貂蝉伸手到额上轻轻理了理那飘逸的头纱，然后两只纤手反背到身后，
也没见她怎么使力，一直束缚在胸前的那副轻纱文胸便被解开了，两只白嫩丰满的巨乳迫不及待地跳了出来，
那粉红的乳尖已经膨胀得有樱桃大小，一对白馥馥、颤巍巍的丰腻雪乳挂在她赤裸的白生生的身子上，
简直是一副无以伦比的美妙图画。\n"NOR);
                        break;
                case(1):
                        tell_room(environment(),HIR"紧接着貂蝉就用自己的白葱纤手捧起那对白皙嫩滑的巨乳，
眼眸凝视着挺直的肉棒，向前一凑把你的大肉棒夹在了当中。大肉棒温柔的陷入两颗乳球所夹出的深遂沟缝之中，
她张开小嘴将唾液轻轻的滴落在肉棒上面，让肉棒充分地润湿，接着再度用乳房紧紧的夹住。\n"NOR);
                        break;
                case(2):
                        tell_room(environment(),HIM"貂蝉两手轻轻压住自己充满弹力的硕大乳房，令被包围在中央的肉棒感受到一种间接的按压，
她专注的压住两颗乳球，开始缓慢的上下交错搓揉中央的肉棒那紧迫又叫人兴奋的压力绝对不输给被小穴肉壁来回摩擦的感觉，
而且乳房柔嫩的触感随着一波波来回的搓揉，将这种愉悦的快感深深的印到你心坎里面。那两颗宛如水晶香瓜般的爆乳，
开始摇晃起来，和着湿滑的唾液分别由左右两边接连不断的挤压着肉棒，在唾液特有的润滑效果之下，爆乳果实在肉棒的表面来回跳动，
感觉上随时都会爆开似的！你凝视着正在帮自己乳交的貂蝉，觉得她浑身有种说不出的性感气息将这美好的胴体给衬托的妖艳无比。\n"NOR);
                        break;
				case(3):
                        tell_room(environment(),HIC"貂蝉那两团雪白的乳肉就好像初生婴儿的皮肤那样柔软，光滑，再配以口水和香汗的的润滑，
敏感的龟头一点也没有滞涩的感觉，反而一股凉丝丝，酸麻麻的感觉由龟头传至足底，刺激得你几乎要呻吟出来。\n"NOR);
                        break;
				case(4):
                        tell_room(environment(),HIW"大肉棒被异常柔软滑腻的乳球包裹着，你忍不住轻抚着貂蝉的面颊呻吟起来，
一边开始挺动着胯下的肉棒，那根又粗又长的大肉棒时不时撞在她的樱唇上，更加增添一种淫靡的气息。
而貂蝉微微喘息着，越发飞快的用乳球揉搓肉棒，美目迷离看着不断从自己雪白美乳中冒出的紫红色龟头，
欲望也被彻底点燃。她猛的将自己的一对奶子压到肉棒根部，死死的抵着圆鼓鼓的睾丸。
露出一大截被搓的发红的肉棒，然後粉嫩的舌头挑在马眼上，将细缝里的晶莹液体一舔而尽，
桃花般的俏脸仿佛品尝到了稀世美味一般陶醉不已。粉嫩的舌尖顺着龟头的沟漕仔细的清理起来，
然後又伸向发红的肉棒来回吸吮。不一会就将整个大肉棒舔吸的晶亮，硕大的奶子再次猛搓……\n"NOR);
                        break;
				case(5):
                        tell_room(environment(),HIY"貂蝉艳若桃李的玉脸上挂着浓郁的春意，樱唇似启非启，一对妩媚的桃花眼时不时地抬头看着你，
那眼中的柔情浓的快要化不开。在貂蝉的丰乳与樱唇的双重夹击下，你的欲望膨胀到了一个顶点，
貂蝉好像知道你快要高潮了，更加卖力的搓揉着自己胸前那两团白花花的乳肉，
两颗粉红的樱桃直接磨蹭在你肉棒根部，口中更是一声又一声地发出甜糯的娇吟。\n"NOR);
                        break;
				case(6):
                        tell_room(environment(),HIG"而这时你的大肉棒也在貂蝉纯熟的乳交技巧中，濒临了喷射的临界点，
貂蝉再次轻轻的含住肿胀的肉棒，口中湿滑温热的感觉冲击着你的神经，她将双乳夹的更紧，
接下来同时摇晃起两边的乳房，在双乳的压榨下，大肉棒高耸的举向天际，看着你享受的愉快神情，
貂蝉的脸上充满喜悦的光彩，更加积极的摆动双乳，强烈地挤压着大肉棒。\n"NOR);
                        break;
				case(7):
                        tell_room(environment(),HIM"终于，你忍不住狂吼一声，一阵酥麻快感从肉棒传导到龟头，紫红色的大肉棒一阵乱抖，
白浊滚烫的液体从那马眼中喷出，不偏不倚地射在貂蝉高昂的玉脸上，她一脸享受的闭上双眼，
长长的睫毛微微颤动，扬着那张白玉雕成的脸庞，承受你灼热精液的浇灌。那浓浓的白色精液挂在她完美无瑕的玉脸上，
从高挺的琼鼻和丰艳的樱唇都一一涉及，还有几丝顺着颀长的脖颈向下滑落到那对白玉般的大奶子上，
这使得那张温柔妩媚的容颜显得无比淫靡，但貂蝉却十分享受地仰着脸地接受着，似乎将这些男性精华当作至宝般。\n"NOR);
                        break;
				case(8):
                        tell_room(environment(),HIR"有几滴白浊精液甚至落在了她长长的眼睫毛上，貂蝉伸出一只涂着香芋紫色指甲油的白葱纤指，
轻轻的将脸上的精液一一收拾抹掉，被你的精液涂抹过的容颜好像更多了一层光华一般，
使得那张玉脸更加艳色无边。等到一切都收拾干净，貂蝉将那根粘满了精液的纤指伸入檀口，
那条鲜红的丁香小舌轻轻一卷，便将那根纤指上的精液全部舔光。她终于睁开那对翦水秋瞳，
两道充满柔情蜜意的眼波瞟向你，樱唇翕动着，一股又甜又糯地娇嗔从中流出：“主人，你的精液味道真不错呢。”\n"NOR);
                        break;
                default: 
                        //delete_temp("in_speech", speaker);
                        return;

        }
        call_out("play_sound_1",1,speaker,++index);
}
void play_sound_2(object speaker,int index) 
{
        if(!environment())
                return;
        if(!speaker)
                return;
      //  if (environment(speaker)->query("short") != "温柔乡")
     //   {
       //      write(HIR "貂蝉已被你挑逗的瘫软在怀中，衣衫不整，媚眼如丝，胸前一对鼓胀的大奶子也呼之欲出。
//她面红耳赤的抓住你作怪的手，吐气如兰：“好老公，咱们回温柔乡吧。婵儿想要你，想要你操我……”\n" NOR);
  //              return;
  //      }
      switch (index)  
	{
                case(0):
                        tell_room(environment(),HIG"你走到合欢床边仰面躺下，貂蝉则180度的爬在你身上，她的阴户压在你的脸部。
你抓住貂蝉的头轻轻压下去，貂蝉顺势握住你坚硬如铁的大肉棒，她微微张开小嘴，慢慢地将你的大肉棒含了进去，
轻轻上下舔拭，一吞一吐配合舌头的动作，慢慢套弄你的大肉棒，然后慢慢地将你的大肉棒含入她那迷人的小嘴中不断吞吐着，
并用她的舌尖一直在龟头上打转舔吮，而她的香艳小嘴更以高速度地上下吮吸，让你更加兴奋。\n"NOR);
                        break;
                case(1):
                        tell_room(environment(),HIR"你兴奋地轻抓貂蝉的蜜桃臂，将她的下阴压向你嘴边，用力吸着她的阴唇。
而你的大肉棒也一寸寸地深入貂蝉美妙的小嘴，直到她的唇触及你肉棒根部。
感觉着貂蝉将你的大肉棒整根含入，你觉得肉棒胀得似乎又更大了。\n"NOR);
                        break;
                case(2):
                        tell_room(environment(),HIM"貂蝉赤裸的趴在你身上吞吐着你的大肉棒，一会儿舔弄你的蛋蛋，一会儿将纤细的手指摩擦你屁眼周围，
让你更加的兴奋，欲念大炽。你兴奋之余舌头往貂蝉的美穴拼命舔弄，貂蝉顿时开始哼哼唧唧的呻吟起来，
她屁股用力下压，将花心封住你的嘴。你一边舔弄貂蝉的美穴，一边双手顺着她美妙的身子游移，并揉捏着她美丽的翘臀。
之后你分开她阴道边的大阴唇，用舌尖去舔她的阴核，逗得她下体一颤一颤的，香淫的爱液不断溢出流到你的嘴里。\n"NOR);
                        break;
				case(3):
                        tell_room(environment(),HIC"你的大肉棒被貂蝉吸弄的越来越大，越来越鼓胀。她的樱桃小口含着大肉棒更激烈地吞吐，
性感迷人的小嘴还发出噗滋噗滋的声音。你用力把脸整个贴到香艳淫糜的肉穴，用食指轻轻玩弄着她的阴核，
再慢慢拨开那诱人的阴唇，食指跟中指一起慢慢滑进她的阴道。来回抽送不过五下，伸出来一看，
她的爱液竟然多到从你的指尖滴下来，这世上难得一见的名器美穴，让你的欲火越烧越旺。\n"NOR);
                        break;
				case(4):
                        tell_room(environment(),HIW"你先用舌尖在貂蝉的小肉芽上绕圈圈，由慢而快，然后出其不意地狠狠舔了她阴唇一口。
“喔！”貂蝉情不自禁的叫了出来，你继续舔着她的美穴，貂蝉白嫩修长的大腿也越夹越紧，
爱液不断地从阴道中流出，她迷乱的心情已被推往亢奋的欲潮。\n"NOR);
                        break;
				case(5):
                        tell_room(environment(),HIY"貂蝉那若隐若现的迷人肉缝沾满着湿淋淋的淫水，两片鲜红的阴唇一张一合的动着，
就像她脸蛋上的樱唇小嘴同样充满诱惑。你一会儿用手先揉捏阴唇，一会儿舔弄阴蒂，
舔得她既酥麻又酸痒，不禁浑身颤抖着，你的手上也沾满了淫水。\n"NOR);
                        break;
				case(6):
                        tell_room(environment(),HIG"忽然，貂蝉骑坐在你脸上的屁股猛地用力摆动起来，前后上下疯狂的扭动，
你知道她要高潮了，于是伸直双手抓向她的奶子用力揉捏起来，舌尖也更加疯狂地舔弄向她淫水潺潺的蜜穴。
貂蝉的丁香妙舌也更加卖力拼命的舔弄你的大肉棒，你再也忍不住双腿夹着她的螓首，
腰部用力挺动抽插着她的香嫩小嘴。随着貂蝉屁股的剧烈扭动和你舌尖的疯狂舔弄，忽然貂蝉如遭雷击，
“啊……”蜜穴内一道洪流激射而出，受到如此强烈刺激，你再也忍耐不住，
大肉棒疯狂耸动几下浓浓的精液也喷射而出直达貂蝉的喉咙，两人同时达到了高潮了。
貂蝉蜜穴中流出的淫水弄得你满头满脸都是，小穴内的嫩肉还一张一合缓缓翕张着。\n"NOR);
                        break;
				case(7):
                        tell_room(environment(),HIM"貂蝉撑着你的双腿慢慢直起身子，转过身轻轻趴在你宽阔的胸膛上。
她朦胧迷离的美目含情脉脉地注视着你，月容之上满含羞意，更显得娇媚艳丽，温玉满怀，
呵气如兰，淡淡体香扑鼻而来，举手投足间散发着诱人的绝世风情，你心满意足的把她拥入怀中。\n"NOR);
                        break;
				case(8):
                        tell_room(environment(),HIR"貂蝉温顺而羞赫的躺在你怀中，成熟丰满、粉妆玉琢、柔肌滑肤的胴一丝不挂地紧贴着你。
那仿佛羊脂白玉般的香腮嫣红迷人，眉眼之间隐含高潮后的春意，宛如芙蓉般娇艳。你搂着她盈盈一握的纤腰，
看着这么一具充满着诱惑力的赤裸玉体，只觉自己心旌摇荡，难以自持，欲火再次腾升，
刚射精过的大肉棒再次坚硬、挺立起来，只想要将这个绝色美人儿压在身下，肆意冲刺，纵情驰骋！\n"NOR);
                        break;
                default: 
                        //delete_temp("in_speech", speaker);
                        return;

        }
        call_out("play_sound_2",1,speaker,++index);
}
void play_sound_3(object speaker,int index) 
{
        if(!environment())
                return;
      if(!speaker)
                return;
     //   if (environment(speaker)->query("short") != "温柔乡")
    //    {
    //         write(HIR "你抱着貂蝉的丝袜美腿，一阵心悸神摇。忍不住把嘴凑到她秀美纤细的玉足上舔舐起来，貂蝉羞红了脸，轻轻推开你，媚眼如丝吐气如兰：“好老公，咱们回温柔乡吧。婵儿想要你，想要你操我……”\n" NOR);
    //            return;
    //    }
      switch (index)  
	{
                case(0):
                        tell_room(environment(),HIG"貂蝉一丝不挂的诱人胴体丰姿绰约，浑然天成。那清丽脱俗偏又冶艳娇媚的玉容，
那秀美柔韧并且晶莹润泽的玉颈，那洁白细腻凝着温滑脂香的高耸玉峰。
还有那圆润剔透的玉脐、那修长柔美的玉腿、那片萋萋芳草掩映下神秘的幽谷、
那修长玉腿无意识的开合下若隐若现的桃园玉溪。\n"NOR);
                        break;
                case(1):
                        tell_room(environment(),HIR"此时，这具性感赤裸的身体如一只大白羊躺在床上，除了她性感大腿上还穿著透明的黑色连裤丝袜外，
那雪白的身体已经全部暴露在你的面前，让你的大肉棒更加挺硬。过了一会，忽然你感觉有个什么东西在轻触你的下体，
你伸手去抓，竟然握住了貂蝉穿著薄薄的黑丝袜的纤美小脚。一阵快感从下体传到脑中，你的心狂跳了起来。\n"NOR);
                        break;
                case(2):
                        tell_room(environment(),HIM"你用手握着貂蝉的左脚，穿着黑色丝袜的脚显得是那么的光滑和细嫩。
你轻轻的抚摸着，她的脚趾在你的下体不住的扭动，你的大肉棒更加鼓胀，撑在裤子上难受异常。
你用手捏弄着貂蝉的脚趾，轻轻搔了一下她的脚心，她的脚猛的缩了回去。
过了一会，你挺立的大肉棒又被貂蝉的左脚压住，并轻轻的揉动了起来。\n"NOR);
                        break;
				case(3):
                        tell_room(environment(),HIC"你握住貂蝉白晰的玉足拉到自己面前，肉棒在光滑细腻的脚背上摩擦，
划出一个又一个带着粘液的圈。好美好嫩的小脚，丝袜下的皮肤又白又嫩，皮下的青筋隐约可见。
我忍不住把貂蝉柔嫩的脚掌并拢夹住肉棒，作抽插动作。\n"NOR);
                        break;
				case(4):
                        tell_room(environment(),HIW"貂蝉脚掌的纹路隔着丝袜摩挲着大肉棒，让你的快感一阵比一阵强烈。
貂蝉似乎很怕痒，轻轻娇笑着把腿收回，你又顽强的抓住脚腕拉回来。\n"NOR);
                        break;
				case(5):
                        tell_room(environment(),HIY"龟头在一根根纤细的脚趾缝处窜来窜去，貂蝉咯咯娇笑着花枝乱颤，
连胸前的两个大奶子也一颤一颤的，荡起层层乳波。你将貂蝉的秀足把玩了好久，
坚挺的大肉棒也涨得似乎要爆炸一般。\n"NOR);
                        break;
				case(6):
                        tell_room(environment(),HIG"貂蝉冲着你妩媚一笑，撒娇的将腿抬起，将她的丝袜美腿放在我的下体，
用脚趾拔动着你的大肉棒，顿时你的肉棒高高挺起顶住了她的玉足。\n"NOR);
                        break;
				case(7):
                        tell_room(environment(),HIM"貂蝉嫩滑玉趾轻轻地磨擦着你的龟头，她用一双丝袜美脚夹住你的肉棒，
用柔软肥厚的脚掌来回摩擦，不时再换成用大脚趾和第二个脚趾夹住肉棒，上下套弄。
不多久，你感到小腹一热，身子一哆嗦，大肉棒不自禁的跳动起来，
龟头颤抖着将一股股白色的精液射到貂蝉粉白娇嫩的玉足上，
使得性感丝袜上一片白色的粘糊。\n"NOR);
                        break;
				case(8):
                        tell_room(environment(),HIR"貂蝉淫荡的轻笑着，用玉脚把你肉棒上的精液轻轻拭去，
你低头瞧着她用穿著丝袜的玉足将最后一点精液清理干净。然后用脚尖勾着你的大肉棒，
娇羞地微闭双眼，轻启樱唇对着你，她的红唇晶莹透亮，吐气如兰。你搂着她的纤腰轻轻吻向她的小嘴，
貂蝉嘤的一声，软倒在床上。你感到她的嘴温温湿湿的有一种很香的味道，过一会儿她双手环住我的头颈紧紧抱住我，
她的头斜靠我的脸颊，你甚至可以听到一阵一阵低沉喘息声从她口中传过来，不久她开始伸出香舌舔你的嘴唇，
并且深深的吸住我的嘴，发出啧啧的声音。然后你的嘴唇被幽香的舌头顶开，
貂蝉的香舌往我的口中伸去，而你也情不自禁的伸出舌头与她纠缠在一起，搅动着，纠缠着。\n"NOR);
                        break;
                default: 
                        //delete_temp("in_speech", speaker);
                        return;

        }
        call_out("play_sound_3",1,speaker,++index);
}
void play_sound_4(object speaker,int index) 
{
        if(!environment())
                return;
        if(!speaker)
                return;
   //     if (environment(speaker)->query("short") != "温柔乡")
    //    {
   //          write(HIR "貂蝉眼神迷离，一只手按在自己硕大的奶子上用力由捏着，另一只手就要伸向不断纠缠紧紧夹着的双腿根部。忽然，她好像想起什么似的，整了整凌乱的衣衫，又把双手放正。\n" NOR);
   //             return;
   //     }
      switch (index)  
	{
                case(0):
                        tell_room(environment(),HIG"貂蝉秀眉微蹙，媚眼迷离，情欲如烈焰赤裸裸地袒裎在眼中。
她打开双腿，美丽的芳草地尽头是诱人的桃源胜地，上下两片花唇守着她的蜜穴入口，
两片花唇嫩嫩欲滴，含苞待放，花唇中是一条美丽的嫩穴，
密而狭窄地合着，只有她口中提到的主人享用过。\n"NOR);
                        break;
                case(1):
                        tell_room(environment(),HIR"貂蝉的手慢慢伸向自己神密茵黑的玉腿根部，摸索着，轻轻着柔弄无比的微隆阴阜上，
柔柔的幽幽芳草，美丽的小瑶鼻中不断娇羞的呻吟着，手指轻轻柔弄着那光滑白嫩、密而狭窄处女玉沟。\n"NOR);
                        break;
                case(2):
                        tell_room(environment(),HIM"那柔软滋润处子幽谷玉溪，被貂蝉用手掌轻地揉捏抚弄着的时候，
整个贞洁幽谷桃园都随着手的动作紧缩着，蠕动着，隐隐探头露出的粉红珍珠更是极力膨胀，
屹立在貂蝉处子桃园内已经蔓延四溢而出的玉液春水中，就如艳阳暖春里展开的靡靡娇花终于结出了丰润的果实，
而且如斯地粉嫩诱人，散发出无穷的诱惑力，简直中人欲醉！\n"NOR);
                        break;
				case(3):
                        tell_room(environment(),HIC"接着貂蝉右手用食指和无名指分开两片粉红的阴唇，在那细柔卷曲的阴毛中，
微凸娇软的阴阜下，找到那已经充血勃起、柔嫩无比的娇小阴蒂，中指探进淫滑湿濡的玉沟，
抚住那同样充血的柔嫩阴唇，三根手指一齐揉压、搓弄，还不时抽出插在蜜穴中手指，
把沾在手指上的花蜜放在尖嫩的樱桃小口中一阵吮吸。\n"NOR);
                        break;
				case(4):
                        tell_room(environment(),HIW"当貂蝉两根手指轻轻捏住自己那敏感万分、娇滑柔嫩的珍珠揉弄轻搓时，
“啊……”一声迷乱狂热而又羞怯的娇喘，强烈的快感犹如酥麻的电流，从珍珠直传到她的灵魂深处，
貂蝉一阵快乐的颤抖，花房内分泌出鲜美的蜜汁，流出小蜜壶，滋润了整个花谷，浇湿了她的芳草地。\n"NOR);
                        break;
				case(5):
                        tell_room(environment(),HIY"貂蝉不禁探出手指，轻柔地触摸逗弄娇怯粉嫩的珍珠，彻底感受它的滑腻滋润。
另一只手缓慢地、颤抖地伸手抚上自己晶莹润泽的少女圣峰，微微触碰、细细揉捏，轻推盘拿、摩挲逗弄。\n"NOR);
                        break;
				case(6):
                        tell_room(environment(),HIG"那出水芙蓉般嫣红可爱的葡萄，在貂蝉的揉捏下感受到的阵阵酥麻轻颤。
雪白的极品玉峰充满了快乐，不停的弹跳，鲜红的红樱桃骄傲挺立着、绽放着。
“啊……唔……”貂蝉快乐地娇声欢叫。雪玉般晶莹的酥胸急速起伏，
淡淡的乳晕也变成了娇艳的桃红色，她已完全沉溺在情欲中。\n"NOR);
                        break;
				case(7):
                        tell_room(environment(),HIM"貂蝉抚摩着自己的玉体，欲火如焚，那下身深处的幽径越来越感到一阵强烈的空虚和酥痒，
一股渴望被充实、被填满、被紧胀，被主人猛烈占有、更直接强烈地肉体刺激占据了脑海的一切。
貂蝉芳心欲念高炽，但又娇羞万般，只见她那秀美的娇靥因熊熊的肉欲淫火和羞涩而胀得火红一片，
玉嫩娇滑的粉脸烫得如沸水一样，含羞轻掩的美眸半睁半闭。此时的貂蝉已春潮翻滚，欲海横流。\n"NOR);
                        break;
				case(8):
                        tell_room(environment(),HIR"蜜洞幽径之内淫水越来越多，顺着修长笔直的美腿流到床单上，
淫浪的呻吟声也从貂蝉的樱桃小嘴之中脱口而出，“啊……好舒服……啊……好爽……啊……要高潮了……啊……”
淫声之际，从貂蝉下身蜜洞花心的深处向外喷泄着大量的爱液，她自慰着达到了快乐高潮。\n"NOR);
                        break;
                default: 
                        //delete_temp("in_speech", speaker);
                        return;

        }
        call_out("play_sound_4",1,speaker,++index);
}


int accept_fight(object ob)
{
        kill_ob(ob);
        return -1;
}

int accept_kill(object ob)
{
        return 1;
}

int accept_hit(object ob)
{
        kill_ob(ob);
        return -1;
}
mixed hit_ob(object me, object ob, int damage_bouns)
{
	ob->start_busy(5 + random(6));
	me->receive_wound("qi", 180000 + random(180000), ob);
        return HIY "$N" HIY "娇喝一声，双手并拢，一招「貂蝉拜月」，劲气向$n" HIY "袭去。\n" NOR;
}
