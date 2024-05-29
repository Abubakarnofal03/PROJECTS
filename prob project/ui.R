library(shiny)
library(shinydashboard)
library(shinyjs)

# Define UI for application
ui <- navbarPage(
  title = "Student Performance Analysis",
  tabPanel("About",
           fluidPage(
             h1("About This App"),
             p("This app analyzes student performance in his/her study."),
             p("It describes the effects of following factors : "),
             br(),
             p("1. Gender"),
             p("2. ethinicity/race"),
             p("3. Parental Education"),
             p("4. Lunch"),
             p("5. Test preperation"),
             br(),
             p("and the result is shown in math scores,reading scores, writing scores"),
             p("Explore different tabs to view histograms, boxplots, probability distributions, regression models, and scatter plots."),
             h2("TEAM MEMBERS"),
             p("M. Abubakar          21F-9278"),
             p("Zain Babar           21F-9341"),
             p("Maher Abdullah       22F-3178"),
             p("Hafiz Arsal          22F-3175")
           )
  ),
  tabPanel("Math Scores", 
           plotOutput("math_histogram"),
           br(),
           plotOutput("math_boxplot"),
           verbatimTextOutput("mean_mode_text_math")
  ),  # Display mean and mode
  
  tabPanel("Reading Scores", 
           plotOutput("reading_histogram"),
           br(),
           plotOutput("reading_boxplot"),
           verbatimTextOutput("mean_mode_text_reading")
  ),
  
  tabPanel("Writing Scores",
           plotOutput("writing_histogram"),
           br(),
           plotOutput("writing_boxplot"),
           verbatimTextOutput("mean_mode_text_writing")
  ),  # Display mean and mode
  
  tabPanel("Probability Distribution",
           plotOutput("math_distribution"),
           br(),
           plotOutput("reading_distribution"),
           br(),
           plotOutput("writing_distribution")
  ),
  
  tabPanel("Regression Model",
           plotOutput("math_regression"),
           br(),
           plotOutput("reading_regression"),
           br(),
           plotOutput("writing_regression")
  ),
  
  tabPanel("Scatter Plot",
           plotOutput("scatter_plot")
  ),
  
  # Inline CSS to change the background color of the navbar
  tags$style(HTML(".navbar { background-color: #000000; }")),
  # To change the color of text
  tags$style(HTML(".navbar-default .navbar-nav > li > a { color: #ffffff; }")),
  
  # To change the background color of the tabPanel
  tags$style(HTML(".navbar-default .navbar-nav > li > a { background-color: #000000; }")),
  
  # To change the color of the text on the tabPanel
  tags$style(HTML(".nav-tabs>li>a {color: #ffffff;}"))
)
