# Laboratorio 1: GitHub
## Guía de instrucciones

Presentar un informe con capturas de pantalla en las partes indicadas:

### Parte 1: Crear una cuenta y un repositorio en Github

1.  **Crear una cuenta en Github:**
    *   Accede a la página principal de Github: [https://github.com](https://github.com).
    *   Haz clic en el botón "Sign up" en la esquina superior derecha.
    *   Introduce tu correo electrónico, contraseña y nombre de usuario.
    *   Sigue las instrucciones para completar el proceso de registro.

Incluir en el informe la URL del perfil de usuario de GitHub.

2.  **Crear un repositorio:**
    *   Una vez que hayas iniciado sesión en Github, haz clic en el botón verde "New" en la esquina superior izquierda de la página.
    *   Introduce un nombre para tu repositorio.
    *   Opcionalmente, puedes añadir una descripción.
    *   Elige si quieres que el repositorio sea público o privado.
    *   Haz clic en el botón verde "Create repository".

Incluir una captura de pantalla del repositorio recién creado.

3.  **Clonar un repositorio localmente:**
    *   Abre tu terminal o línea de comandos.
    *   Navega hasta el directorio donde quieres clonar el repositorio.
    *   Utiliza el comando `git clone` seguido de la URL del repositorio.
    *   Ejemplo: `git clone https://github.com/usuario/repositorio.git`

Incluir una captura de la terminal o del explorador con el repositorio clonado.

### Parte 2: Inicializar un repositorio localmente y sincronizarlo con Github

NOTA: Éste es un repositorio distinta al de la anterior parte.

1.  **Inicializar un repositorio localmente:**
    *   Abre tu terminal o línea de comandos.
    *   Navega hasta el directorio que quieres convertir en un repositorio.
    *   Utiliza el comando `git init`.
2.  **Sincronizar un repositorio local con Github:**
    *   Crea un nuevo repositorio en Github (sigue los pasos de la Parte 1).
    *   Crea uno o más archivos y agregalos al área de "staging" usando `git add <nombres de los archivos>` o `git add .` para agregar todos los archivos en el directorio actual.
    *   En tu terminal, añade el repositorio remoto de Github con el comando `git remote add origin <URL del repositorio>`.
    *   Haz commit de tus cambios locales con `git commit -m "Mensaje del commit"`.
    *   Sube tus cambios a Github con el comando `git push -u origin main`.

Incluir una captura con el commit y push exitoso. Investigar y explicar las diferentes áreas (directorio de trabajo, staging, repositorio local y repositorio remoto).

### Parte 3: Crear un branch, hacer un pull request y hacer el merge

1.  **Crear un branch:**
    *   Utiliza el comando `git checkout -b <nombre del branch>` para crear un nuevo branch y cambiarte a él.
2.  **Realizar cambios:**
    *   En este nuevo branch, realizar cambios en los archivos creados en la parte 2.2. Repetir los pasos con `git add .` > `git commit -m "Mensaje del commit"` > `git push -u origin main`. Éste es el flujo de trabajo principal en Git para guardar nuestros cambios.

Incluir una captura con el nuevo branch creado, y el commit y push exitoso.

3.  **Hacer un pull request:**
    *   Sube tus cambios al branch remoto con `git push origin <nombre del branch>`.
    *   En Github, ve a la página del repositorio.
    *   Haz clic en la pestaña "Pull requests".
    *   Haz clic en el botón verde "New pull request".
    *   Selecciona el branch que quieres mergear.
    *   Añade un título y una descripción.
    *   Haz clic en el botón verde "Create pull request".
4.  **Hacer el merge:**
    *   En la página del pull request, revisa los cambios.
    *   Si todo está correcto, haz clic en el botón verde "Merge pull request".
    *   Elige el tipo de merge que quieres hacer.
    *   Haz clic en el botón "Confirm merge".

Incluir una captura con la aprobación del pull request.

Si hubieron conflictos en el proceso del pull request, incluir una captura de los conflictos y una explicación de la causa de los conflictos, y cómo pueden ser resueltos.

Esto concluye el Laboratorio 1.