import{s as A,n as E,f as V,a as W,u as X,g as Y,b as J,r as K}from"../chunks/scheduler.DGpLaggK.js";import{S as B,i as I,e as x,c as y,o as L,k as b,g as j,d as k,s as H,a as q,f as $,h as v,u as Q,t as Z,b as ee,j as te,n as G,p as S,q as F,B as M,l as C,m as O,r as N}from"../chunks/index.CuBF9aYE.js";import{e as P}from"../chunks/each.D6YF6ztN.js";function se(a){let e,t='<p class="px-4 py-2 bg-white text-slate-950 font-medium">Connect with me ↓</p> <div class="flex flex-col gap-4 items-center justify-center"><a href="mailto:aquon_bovell@outlook.com"><b class="pr-2">Email</b>aquon_bovell@outlook.com</a> <p><b class="pr-2">GitHub</b> <a href="https://github.com/aquonbovell" target="_blank" class="text-violet-400">aquon_bovell<sup class=""><span class="text-xs scale-75 pl-0.5"><i class="fa-solid fa-arrow-up-right-from-square text-xs scale-[75%]"></i></span></sup></a></p> <p><b class="pr-2">LinkedIn</b> <a href="www.linkedin.com/in/aquon-bovell-184874163" target="_blank" class="text-violet-400">Aquon Bovell<sup class=""><span class="text-xs scale-75 pl-0.5"><i class="fa-solid fa-arrow-up-right-from-square text-xs scale-[75%]"></i></span></sup></a></p></div>';return{c(){e=x("footer"),e.innerHTML=t,this.h()},l(n){e=y(n,"FOOTER",{id:!0,class:!0,"data-svelte-h":!0}),L(e)!=="svelte-1dv3hob"&&(e.innerHTML=t),this.h()},h(){b(e,"id","contact"),b(e,"class","py-20 sm:py-32 bg-black border-t border-solid border-violet-950 flex flex-col gap-4 sm:gap-8 justify-center items-center")},m(n,s){j(n,e,s)},p:E,i:E,o:E,d(n){n&&k(e)}}}class le extends B{constructor(e){super(),I(this,e,null,se,A,{})}}function R(a,e,t){const n=a.slice();return n[2]=e[t],n[4]=t,n}function U(a){let e,t,n=a[2].name+"",s,o,f;return{c(){e=x("a"),t=x("p"),s=Z(n),o=H(),this.h()},l(u){e=y(u,"A",{href:!0,class:!0,target:!0});var d=q(e);t=y(d,"P",{});var _=q(t);s=ee(_,n),_.forEach(k),o=$(d),d.forEach(k),this.h()},h(){b(e,"href",f=a[2].link),b(e,"class","duration-200 hover:text-violet-400 font-bold"),b(e,"target",a[4]===2?"_blank":"")},m(u,d){j(u,e,d),v(e,t),v(t,s),v(e,o)},p(u,d){d&2&&n!==(n=u[2].name+"")&&te(s,n),d&2&&f!==(f=u[2].link)&&b(e,"href",f)},d(u){u&&k(e)}}}function ae(a){let e,t,n='<b class="font-bold poppins text-2xl">Aquon.Bovell</b>',s,o,f,u,d='<div class="absolute top-0 right-full w-full h-full bg-violet-400 opacity-20 group-hover:translate-x-full z-0 duration-200"></div> <a class="relative z-9" href="#contact">Get in touch</a>',_,h=P(a[1]),r=[];for(let i=0;i<h.length;i+=1)r[i]=U(R(a,h,i));return{c(){e=x("header"),t=x("h1"),t.innerHTML=n,s=H(),o=x("div");for(let i=0;i<r.length;i+=1)r[i].c();f=H(),u=x("button"),u.innerHTML=d,this.h()},l(i){e=y(i,"HEADER",{class:!0});var p=q(e);t=y(p,"H1",{class:!0,"data-svelte-h":!0}),L(t)!=="svelte-vw3ji5"&&(t.innerHTML=n),s=$(p),o=y(p,"DIV",{class:!0});var l=q(o);for(let w=0;w<r.length;w+=1)r[w].l(l);f=$(l),u=y(l,"BUTTON",{class:!0,"data-svelte-h":!0}),L(u)!=="svelte-1jm2dz2"&&(u.innerHTML=d),l.forEach(k),p.forEach(k),this.h()},h(){b(t,"class","font-medium"),b(u,"class","blueShadow relative overflow-hidden px-5 py-2 group rounded-full bg-white text-slate-950"),b(o,"class","sm:flex items-center gap-4 hidden"),b(e,"class",_="sticky z-[10] top-0 duration-200 px-10 flex items-center justify-between border-b border-solid "+(a[0]>0?" py-4 bg-slate-950 border-violet-950":" py-6 bg-transparent border-transparent"))},m(i,p){j(i,e,p),v(e,t),v(e,s),v(e,o);for(let l=0;l<r.length;l+=1)r[l]&&r[l].m(o,null);v(o,f),v(o,u)},p(i,[p]){if(p&2){h=P(i[1]);let l;for(l=0;l<h.length;l+=1){const w=R(i,h,l);r[l]?r[l].p(w,p):(r[l]=U(w),r[l].c(),r[l].m(o,f))}for(;l<r.length;l+=1)r[l].d(1);r.length=h.length}p&1&&_!==(_="sticky z-[10] top-0 duration-200 px-10 flex items-center justify-between border-b border-solid "+(i[0]>0?" py-4 bg-slate-950 border-violet-950":" py-6 bg-transparent border-transparent"))&&b(e,"class",_)},i:E,o:E,d(i){i&&k(e),Q(r,i)}}}function ne(a,e,t){let{y:n}=e,{tabs:s=[{name:"Projects ",link:"#projects"},{name:"About me",link:"#about"},{name:"GitHub",link:"https://www.github.com/aquonbovell"}]}=e;return a.$$set=o=>{"y"in o&&t(0,n=o.y),"tabs"in o&&t(1,s=o.tabs)},[n,s]}class oe extends B{constructor(e){super(),I(this,e,ne,ae,A,{y:0,tabs:1})}}function re(a){let e=!1,t=()=>{e=!1},n,s,o,f,u='<i class="fa-solid fa-arrow-up"></i>',d,_,h,r,i,p,l,w,D;V(a[6]),V(a[7]),h=new oe({props:{y:a[0],innerHeight:a[2]}});const z=a[5].default,g=W(z,a,a[4],null);return p=new le({}),{c(){s=x("div"),o=x("div"),f=x("button"),f.innerHTML=u,_=H(),G(h.$$.fragment),r=H(),g&&g.c(),i=H(),G(p.$$.fragment),this.h()},l(c){s=y(c,"DIV",{class:!0});var m=q(s);o=y(m,"DIV",{class:!0});var T=q(o);f=y(T,"BUTTON",{class:!0,"data-svelte-h":!0}),L(f)!=="svelte-72cqu4"&&(f.innerHTML=u),T.forEach(k),_=$(m),S(h.$$.fragment,m),r=$(m),g&&g.l(m),i=$(m),S(p.$$.fragment,m),m.forEach(k),this.h()},h(){b(f,"class","ml-auto rounded-full bg-slate-900 text-violet-400 px-3 sm:px-4 hover:bg-slate-800 cursor-pointer aspect-square grid place-items-center"),b(o,"class",d="fixed bottom-0 w-full duration-200 flex p-10 z-[10] "+(a[0]>0?" opacity-full pointer-events-auto":" pointer-events-none opacity-0")),b(s,"class","container relative flex flex-col max-w-[1400px] mx-auto w-full text-sm sm:text-base min-h-screen")},m(c,m){j(c,s,m),v(s,o),v(o,f),v(s,_),F(h,s,null),v(s,r),g&&g.m(s,null),v(s,i),F(p,s,null),l=!0,w||(D=[M(window,"scroll",()=>{e=!0,clearTimeout(n),n=setTimeout(t,100),a[6]()}),M(window,"resize",a[7]),M(f,"click",ie)],w=!0)},p(c,[m]){m&1&&!e&&(e=!0,clearTimeout(n),scrollTo(window.pageXOffset,c[0]),n=setTimeout(t,100)),(!l||m&1&&d!==(d="fixed bottom-0 w-full duration-200 flex p-10 z-[10] "+(c[0]>0?" opacity-full pointer-events-auto":" pointer-events-none opacity-0")))&&b(o,"class",d);const T={};m&1&&(T.y=c[0]),m&4&&(T.innerHeight=c[2]),h.$set(T),g&&g.p&&(!l||m&16)&&X(g,z,c,c[4],l?J(z,c[4],m,null):Y(c[4]),null)},i(c){l||(C(h.$$.fragment,c),C(g,c),C(p.$$.fragment,c),l=!0)},o(c){O(h.$$.fragment,c),O(g,c),O(p.$$.fragment,c),l=!1},d(c){c&&k(s),N(h),g&&g.d(c),N(p),w=!1,K(D)}}}function ie(){document.body.scrollIntoView()}function ce(a,e,t){let{$$slots:n={},$$scope:s}=e;const o=!0;let f,u=0,d=0;function _(){t(0,f=window.pageYOffset)}function h(){t(2,d=window.innerHeight),t(1,u=window.innerWidth)}return a.$$set=r=>{"$$scope"in r&&t(4,s=r.$$scope)},[f,u,d,o,s,n,_,h]}class pe extends B{constructor(e){super(),I(this,e,ce,re,A,{prerender:3})}get prerender(){return this.$$.ctx[3]}}export{pe as component};
