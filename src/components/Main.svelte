<script>
  import Step from "./Step.svelte";

  let steps = [
    {
      name: "Threads Clone",
      icon: "fa-brands fa-threads",
      description:
        "Threads is a social media app where persons can post what is on their mind. This was created with Next.js, Clerk and ShadCN. Clerk is used for authentication and ShadCN is used for  enhance the user interface and user experience.",
      source: "https://github.com/aquonbovell/threads-app",
      link: "https://threads-app-lime.vercel.app/",
    },
    {
      name: "Where in the World?",
      icon: "fa-solid fa-globe",
      description:
        "Test for model robustness with customized test profiles and receive exhaustive reporting on the performance and potential vulnerabilities of your model.",
      source: "https://github.com/aquonbovell/countries",
      link: "https://countries-tawny-one.vercel.app/",
    },
    {
      name: "Article Summarizer",
      icon: "fa-solid fa-marker",
      description:
        "Augment your datasets with our filters and dataset manipulations to ensure your models are trained on the highest quality datasets (coming soon).",
      source: "https://github.com/aquonbovell/ai-summarizer",
      link: "https://scintillating-duckanoo-11e8d8.netlify.app/",
    },
  ];

  let benefits = [
    {
      metric: "10x",
      name: "a self taught developer",
      description:
        "I taught myself to code using free online resources and absolutely fell in love with the creativity and problem solving that is involved in developing and engineering innovative new online experiences. Starting of with JavaScript, HTML & CSS and evolving my knowledge base to include JavaScript frameworks, backend programming, design, computer vision and much much more.",
    },
    {
      name: "an innovative problem solver",
      description:
        "Known for my innovative approach to problem-solving, I consistently strive to craft unique solutions that push boundaries and exceed expectations. Passionate about tackling complex challenges, I thrive on exploring new design concepts and implementing cutting-edge technologies to deliver exceptional user experiences.",
    },
    {
      name: "an excellent communicator",
      description:
        "As the President of the Computer Science Society, I spearheaded various initiatives that required effective communication and collaboration. From facilitating transparent discussions during regular meetings to organizing workshops and seminars, I demonstrated the value of constructive communication and teamwork to achieve collective goals. My commitment to fostering a collaborative environment extends beyond the society, as I actively seek out opportunities to collaborate with cross-functional teams and leverage diverse perspectives to drive meaningful change and advancement.",
    },
  ];
</script>

<main class="flex flex-col flex-1 p-4 px-10">
  <section
    id="introPage"
    class="grid grid-cols-1 lg:grid-cols-3 gap-10 py-8 sm:py-14"
  >
    <div
      class="flex flex-col lg:justify-center text-center lg:text-left gap-6 md:gap-8 lg:gap-10 lg:col-span-2"
    >
      <h2 class="font-semibold text-4xl sm:text-5xl md:text-6xl">
        Hi! I'm <span class="poppins text-violet-400">Aquon</span> Bovell
        <br />Full Stack
        <span class="poppins text-violet-400">Developer</span>
      </h2>
      <p class="text-base sm:text-lg md:text-xl">
        My <span class="text-violet-400">favorite tech</span> includes Python + Django,
        JavaScript (NEXT.JS or SvelteKit), TailwindCSS, Node.js + Express.js & MongoDB!
      </p>
      <button
        class="blueShadow mx-auto lg:mr-auto lg:ml-0 text-base sm:text-lg md:text-xl poppins relative overflow-hidden px-6 py-3 group rounded-full bg-white text-slate-950"
      >
        <div
          class="absolute top-0 right-full w-full h-full bg-violet-400 opacity-20 group-hover:translate-x-full z-0 duration-200"
        />
        <a class="relative z-9" href="#contact">Get in touch &rarr;</a>
      </button>
    </div>
    <div class="relative shadow-2xl grid place-items-center">
      <img
        src={"images/profile.png"}
        alt="Aquon Bovell"
        class="object-cover z-[2] max-h-[70vh]"
      />
    </div>
    <div class="flex p-0.5 relative w-full mx-auto col-span-full">
      <div
        class="absolute -inset-1 overflow-hidden rounded-md flex items-center justify-center"
      >
        <div
          class="bg-gradient-to-r absolute inset-[-20px] from-violet-800 to-indigo-800 specialSpin"
        />
      </div>
    </div>
  </section>
  <section class="py-20 lg:py-32 flex flex-col gap-24" id="projects">
    <div class="flex flex-col gap-2 text-center">
      <h6 class="text-large sm:text-xl md:text-2xl">
        A few of my creative endeavors.
      </h6>
      <h3 class="font-semibold text-3xl sm:text-4xl md:text-5xl">
        Curious to <span class="poppins text-violet-400">see</span> my work?
      </h3>
    </div>
    <div class="grid grid-cols-1 lg:grid-cols-3 gap-12 lg:gap-10">
      <Step step={steps[0]}>
        <p>
          Threads is a social media app where persons can post what is on their
          mind. This was created with <strong class="text-violet-400"
            >Next.js, Clerk</strong
          >
          & <strong class="text-violet-400">ShadCN!</strong> Clerk is used for authentication
          and ShadCN is used for enhance the user interface and user experience.
        </p>
      </Step>
      <Step step={steps[1]}>
        <p>
          Where in the World? is a Full Stack <strong class="text-violet-400"
            >Next.js</strong
          >,
          <strong class="text-violet-400">Node.js + Express.js</strong>
          & <strong class="text-violet-400">MongoDB</strong> Query application that
          allows a user to search and explore all the countries in the world from
          an API endpoint.
        </p>
      </Step>
      <Step step={steps[2]}>
        <p>
          Article Summarizer is a <strong class="text-violet-400"
            >Svelte + TailwindCSS + TypeScript</strong
          >
          web application, hosted on
          <strong class="text-violet-400">Netlify</strong>, that consumes and
          caches all the article links that the user has submitted and then
          provides a summary of the article.
        </p>
      </Step>
    </div>
  </section>
  <section
    id="about"
    class="py-20 pt-10 lg:pt-16 lg:py-32 flex flex-col gap-16 sm:gap-20 md:gap-24 relative"
  >
    <!-- <div class="z-[-1] bg-violet-950 w-screen left-1/2 -translate-x-1/2 top-0 h-full absolute"> </div> -->
    <div
      class="flex flex-col gap-2 text-center relative before:absolute before:top-0 before:left-0 before:w-2/3 before:h-1.5 before:bg-violet-700 after:absolute after:bottom-0 after:right-0 after:w-2/3 after:h-1.5 after:bg-violet-700 py-4"
    >
      <h6 class="text-large sm:text-xl md:text-2xl">Want to know more?</h6>
      <h3 class="font-semibold text-3xl sm:text-4xl md:text-5xl">
        A bit <span class="poppins text-violet-400">about</span> me.
      </h3>
    </div>
    <p class="mx-auto poppins font-semibold text-lg sm:text-xl md:text-2xl">
      I am . . .
    </p>
    <div class="flex flex-col gap-20 w-full mx-auto max-w-[800px]">
      {#each benefits as benefit, index}
        <!-- <div class="flex flex-col gap-2 mx-auto">
                    <div class="flex items-end gap-4">
                        <p
                            class="poppins text-6xl sm:text-7xl md:text-8xl text-slate-500 font-medium"
                        >
                            {benefit.metric}
                        </p>
                        <p
                            class="text-xl sm:text-2xl md:text-3xl capitalize pb-2"
                        >
                            {benefit.name}
                        </p>
                    </div>
                    <p class="text-center italic">- {benefit.description}</p>
                </div> -->
        <div class="flex gap-6 sm:gap-8">
          <p
            class="poppins text-4xl sm:text-5xl md:text-6xl text-slate-500 font-semibold"
          >
            0{index + 1}
          </p>
          <div class="flex flex-col gap-6 sm:gap-8">
            <h3 class="text-2xl sm:text-3xl md:text-5xl">
              {benefit.name}
            </h3>
            <p>{benefit.description}</p>
          </div>
        </div>
      {/each}
    </div>
    <div>
      <h5 class={" text-2xl sm:text-4xl font-semibold text-center poppins "}>
        The <span class="text-violet-400">Complete</span> Package ?
      </h5>
      <p class="mx-auto text-center py-3">So why not invest?</p>
    </div>
  </section>
</main>
