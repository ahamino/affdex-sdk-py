from PIL import Image
import affdex

def affdex_license():
    return """
              {
                "token":"2d70e932a6974f8d6930e0abc8c267bb5561580efdedd4f6d79ba82a3b93e293",
                "licensor":"Affectiva Inc.",
                "expires":"2016-06-07",
                "developerId":"ahamino+1@gmail.com",
                "software":"Affdex SDK"
              }
           """

def imageResultsCallback(faces, image):
    for id in faces:
        print(faces[id].appearance.glasses)
        print(faces[id].appearance.gender)

if __name__ == "__main__":
   data_folder = "/home/abdelrahman/dev/affdex-sdk/data"
   im = Image.open("/home/abdelrahman/Downloads/demi-more.jpg")
   frame = affdex.Frame(im.size[0], im.size[1],
                        im.tobytes(), affdex.COLOR_FORMAT.BGR, 0.0)

   detector = affdex.PhotoDetector(1, affdex.FaceDetectorMode.SMALL_FACES)
   detector.setLicenseString(affdex_license())
   detector.setClassifierPath(data_folder)
   detector.setImageResultsCallback(imageResultsCallback)
   detector.setDetectGender(True)
   detector.setDetectGlasses(True)
   detector.start()
   detector.process(frame)
   print(im.format, im.size, im.mode)
