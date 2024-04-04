function getCookie(b){let c=`; ${document.cookie}`,a=c.split(`; ${b}=`);if(2===a.length)return
a.pop().split(";").shift()}function sleep(a){return new Promise(b=>{setTimeout(b,a)})}function
afterUrlGenerator(a){return`https://www.instagram.com/graphql/query/?query_hash=3dec7e2c57367ef3da3d987
d89f9dbc8&variables={"id":"${ds_user_id}","include_reel":"true","fetch_mutual":"false","first":"24","after":"${a}"}`}function
unfollowUserUrlGenerator(a){return`https://www.instagram.com/web/friendships/${a}/unfollow/`}let followedPeople,csrftoken=getCookie("csrftoken"),ds_user_id=getCookie
("ds_user_id"),initialURL=`https://www.instagram.com/graphql/query/?query_hash=3dec7e2c57367ef3da3d987d89f9dbc8&variables={"id":"${ds_user_id}
","include_reel":"true","fetch_mutual":"false","first":"24"}`,doNext=!0,filteredList=[],getUnfollowCounter=0,scrollCicle=0;async function 
startScript(){for(var c,d,e,b,f,g=Math.floor;doNext;){let a;try{a=await fetch(initialURL).then(a=>a.json())}
catch(h){continue}followedPeople||(followedPeople=a.data.user.edge_follow.count),doNext=a.data.user.edge_follow.page_info.has_next_page,
initialURL=afterUrlGenerator(a.data.user.edge_follow.page_info.end_cursor),getUnfollowCounter+=a.data.user.edge_follow.edges.length,
a.data.user.edge_follow.edges.forEach(a=>{a.node.follows_viewer||filteredList.push(a.node)}),console.clear(),console.log
(`%c Progress ${getUnfollowCounter}/${followedPeople} (${parseInt(100*(getUnfollowCounter/followedPeople))}%)`,"background:
#222; color: #bada55;font-size: 35px;"),console.log("%c This users don't follow you (Still in progress)","background: #222;
color: #FC4119;font-size: 13px;"),filteredList.forEach(a=>{console.log(a.username)}),await sleep(g(400*Math.random())+1e3),
scrollCicle++,6<scrollCicle&&(scrollCicle=0,console.log("%c Sleeping 10 secs to prevent getting temp blocked","background: #222; 
color: ##FF0000;font-size: 35px;"),await sleep(1e4))}c=JSON.stringify(filteredList),d="usersNotFollowingBack.json",e="application/json",
3b=document.createElement("a"),f=new Blob([c],{type:e}),b.href=URL.createObjectURL(f),b.download=d,b.click(),console.log("%c All DONE!","background: #222;
color: #bada55;font-size: 25px;")}startScript()
//version 3.0
//deberia funcionar al ejecutar en inspeccion de chrome(probar primero con cuenta secundaria)
